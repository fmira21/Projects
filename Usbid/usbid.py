import usb.core

#Создание нового журнала со всеми подключенными девайсами
def new_log():
    dev = usb.core.find(find_all=1)
    fname = input ('Введите имя нового журнала: ')
    log = open(fname, "w")
    for cfg in dev:
        if str(cfg.idProduct) != '1' and str(cfg.idProduct) != '2':
            log.write(str(hex(cfg.idVendor)) + ' : ' + str(hex(cfg.idProduct)) + '\n')
    log.close()
    print ('Сохранено в', fname)

#Запись подключенных девайсов в общий журнал
def accept():
    dev = usb.core.find(find_all=1)
    acc = open("usblog.txt", "a")
    for cfg in dev:
        entry = str(hex(cfg.idVendor)) + ' : ' + str(hex(cfg.idProduct))
        with open("usblog.txt") as file:
            if str(cfg.idProduct) != '1' and str(cfg.idProduct) != '2' and entry not in map(str.strip, file):
                acc.write(str(hex(cfg.idVendor)) + ' : ' + str(hex(cfg.idProduct)) + '\n')
    acc.close()

#Отображение найденных устройств в консоли
def show():
    dev = usb.core.find(find_all=1)
    for cfg in dev:
        if str(cfg.idProduct) != '1' and str(cfg.idProduct) != '2':
            print ('ID производителя:' + str(hex(cfg.idVendor)) + ' ID устройства:' + str(hex(cfg.idProduct)) + '\n')

#Проверка, внесена ли флешка в журнал
def check():
    dev = usb.core.find(find_all=1)
    for cfg in dev:
        if str(cfg.idProduct) != '1' and str(cfg.idProduct) != '2':
            line = str(hex(cfg.idVendor)) + ' : ' + str(hex(cfg.idProduct))
            with open("usblog.txt") as file:
                if line not in map(str.strip, file):
                    print("В журнале нет устройства:")
                    print ('ID производителя:' + str(hex(cfg.idVendor)) + ' ID устройства:' + str(hex(cfg.idProduct)) + '\n')
                else: print('ID производителя:' + str(hex(cfg.idVendor)) + ' ID устройства:' + str(hex(cfg.idProduct)) + " - OK" + '\n')

#Меню
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
