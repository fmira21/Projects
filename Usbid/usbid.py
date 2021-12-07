import usb.core

# Create new log with all connected devices
def new_log():
    try:
        dev = usb.core.find(find_all=1)
    except:
        print ("USB устройств не обнаружено.\nNo USB devices detected.")
        return
    fname = input ('Введите имя нового журнала:\nEnter new log name:')
    log = open(fname, "w")
    for cfg in dev:
        if str(cfg.idProduct) != '1' and str(cfg.idProduct) != '2':
            log.write(str(hex(cfg.idVendor)) + ' : ' + str(hex(cfg.idProduct)) + '\n')
    log.close()
    print ('Сохранено в', fname)
    print ('Saved as', fname)

# Add connected devices to the usblog.txt
def accept():
    try:
        dev = usb.core.find(find_all=1)
    except:
        print ("USB устройств не обнаружено.\nNo USB devices detected.")
        return
    acc = open("usblog.txt", "a")
    for cfg in dev:
        entry = str(hex(cfg.idVendor)) + ' : ' + str(hex(cfg.idProduct))
        with open("usblog.txt") as file:
            if str(cfg.idProduct) != '1' and str(cfg.idProduct) != '2' and entry not in map(str.strip, file):
                acc.write(str(hex(cfg.idVendor)) + ' : ' + str(hex(cfg.idProduct)) + '\n')
    acc.close()

# Show the found devices in the terminal
def show():
    try:
        dev = usb.core.find(find_all=1)
    except:
        print ("USB устройств не обнаружено.\nNo USB devices detected.")
        return
    for cfg in dev:
        if str(cfg.idProduct) != '1' and str(cfg.idProduct) != '2':
            print ('ID производителя (Vendor ID):' + str(hex(cfg.idVendor)) + ' ID устройства (Product ID):' + str(hex(cfg.idProduct)) + '\n')

# Check if a connected device is in the log
def check():
    try:
        dev = usb.core.find(find_all=1)
    except:
        print ("USB устройств не обнаружено.\nNo USB devices detected.")
        return
    for cfg in dev:
        if str(cfg.idProduct) != '1' and str(cfg.idProduct) != '2':
            line = str(hex(cfg.idVendor)) + ' : ' + str(hex(cfg.idProduct))
            with open("usblog.txt") as file:
                if line not in map(str.strip, file):
                    print("В журнале нет устройства (No device in the log):")
                    print ('ID производителя (Vendor ID):' + str(hex(cfg.idVendor)) + ' ID устройства (Product ID):' + str(hex(cfg.idProduct)) + '\n')
                else: print('ID производителя (Vendor ID):' + str(hex(cfg.idVendor)) + ' ID устройства (Product ID):' + str(hex(cfg.idProduct)) + " - OK" + '\n')

# Menu
working = True
while working:
    cmd = input(">>> ")
    if cmd == "new":
        new_log()
    elif cmd == "accept":
        accept()
    elif cmd == "show":
        show()
    elif cmd == "check":
        check()
    elif cmd == "quit":
        working = False
