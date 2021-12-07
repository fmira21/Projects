import urllib.request
import json
import sys
 
bcaddress = input("Enter the Waves blockchain address: ")
limit = input("Enter the tx limit (default: 400): ") 


if (bcaddress and limit):
    response = urllib.request.urlopen('NODE_ADDRESS' + bcaddress + '/limit/' + limit)
else:
    response = urllib.request.urlopen('NODE_ADDRESS' + bcaddress + '/limit/400')

data = json.loads(response.read().decode(response.info().get_param('charset') or 'utf-8'))
negative = 0
argnum = 0

for args in sys.argv:
    argnum += 1

if (argnum == 1):
    sys.exit("Usage:\na) wavesparser.py <Tx type> <Tx version>\nb) tparse.py <Tx type>\nc) tparse.py <Tx version>")
elif ((argnum == 2 or argnum == 3) and (len(sys.argv[1]) > 3)):
    sys.exit("Invalid input")
elif(argnum == 3 and len(sys.argv[2]) > 1):
    sys.exit("Invalid input")

if (argnum == 2 and len(sys.argv[1]) > 1): #Tx
    for json_inner_array in data:
            for json_data in json_inner_array:
                if (json_data["type"] == int(sys.argv[1])):
                    print(json_data)
                    negative = 1
elif (argnum == 2 and len(sys.argv[1]) == 1): #Version
    for json_inner_array in data:
        for json_data in json_inner_array:
            if (json_data["version"] == int(sys.argv[1])):
                print(json_data)
                negative = 1
elif (argnum == 3): #Tx && Version
    for json_inner_array in data:
        for json_data in json_inner_array:
            if (json_data["type"] == int(sys.argv[1]) and json_data["version"] == int(sys.argv[2])):
                print(json_data)
                negative = 1

if (negative == 0):
    sys.exit("Nothing has been found.")
