import openpyxl
import sys
from pathlib import Path
import requests
import time
import numpy as np

try:
    argfile = sys.argv[1]
except:
    sys.exit("Enter the filename!")

curr_list = requests.get('YOUR_API_SUPPORTED_CURRENCIES').json() #Get currency list
supported = [] #Array of supported currencies
unsupported = {"currency": "value"}
currencies = curr_list.get('currencies')
for i in range(len(currencies)):
    supported.append(currencies[i].get('currency'))

xlsx_file = Path(argfile)
wb_obj = openpyxl.load_workbook(xlsx_file)

sheet = wb_obj.active

for row in sheet.iter_rows(min_col = 4, max_col = 4, min_row = 3, values_only = True):
    address = str(row).rstrip('\'\,\)').lstrip('\(\'') #Trim excessive characters
    #print(string)
    requeststring = 'https://api.ethplorer.io/getAddressInfo/' + address + '?apiKey=freekey'
    #print(requeststring)
    response = requests.get(requeststring).json() #Response dict

    print("===============================================================\n")
    print("Address: ", address)
    try:
        print("ETH: ", response.get('ETH').get('balance'))
        time.sleep(1)
        try:
            tokens = response.get('tokens')
            for i in range(len(tokens)):
                print(tokens[i].get('tokenInfo').get('name') + ": ", tokens[i].get('balance'))
                if tokens[i].get('tokenInfo').get('symbol') not in supported:
                    unsupported[tokens[i].get('tokenInfo').get('name')] = tokens[i].get('balance')
                    input_filename=open("out", "a")
                    input_filename.write(str(tokens[i].get('tokenInfo').get('symbol')) + " = " + str(tokens[i].get('balance')))
                    input_filename.close()
            time.sleep(5)
        except:
            print ("No other tokens")
            time.sleep(5)
            continue
    except:
        print("Not accessible, API request limit is expired")
        continue
    #print("Achtung: ", unsupported)
np.save('unsupported.npy', unsupported)

