def mail_check(email):
    # Проверка на количество @
    if email.count('@') > 1 or email.count('@') == 0:
        return (False, 'Wrong number of @ symbols')
    [name,domain] = email.split('@')

    # Проверка длины доменного имени
    if len(domain) < 3:
        return (False, 'Domain name is less than 3 symbols')
    if len(domain) > 256:
        return (False, 'Domain name is longer than 256 symbols')

    # Проверка на наличие точки в доменном имени
    if domain.count('.') == 0:
        return (False, 'Domain name does not include a dot')
    include_domain = domain.split('.')


    # Формируем список с допустимыми символами: a-z, -, _
    correct_list = list(range(ord('a'),ord('z') + 1))
    correct_list.extend([ord('-'), ord('_')])

    for k in include_domain:
        # Проверка на наличие пустых символов между точками
        if k == '':
            return (False, 'Domain name includes empty symbol')

        # Проверяем на наличие недопустимых символов
        for n in k:
            if ord(n) not in correct_list:
                error_msg = "Invalid symbol " + n
                return (False, error_msg)
        if (k[0] == '-') or (k[len(k)-1] == '-'):
            return (False, 'Domain name cannot start or end with "-"')

    # Проверка на длину имени ПЯ
    if len(name) > 128:
        return (False, 'Name is longer than 128 symbols')

    # Добавляем . ; '"' в список символов
    correct_list.extend([ord('.'),ord(';'),ord('"')])

    # Составляем список символов, допустимых для воспроизведения в скобках
    list_inquotes = [ord('!'), ord(','), ord(':')]

    # Дополняем основной список правильных символов списком list_inquotes
    correct_list.extend(list_inquotes)

    # Проверяем парные кавычки
    if name.count('"')%2 != 0:
        return (False, "Non-pair quotation marks")

    # Проверка на две точки в имени
    doubledot = False
        if (k == '.'):
            if doubledot == True:
                return (False, "Two dots in name")
            else:
                doubledot = True

    # Проверка на символ в кавычках и соответствие символа списку допустимых
    inquotes = False
    for k in name:
        if (k == '"'):
            inquotes = not inquotes
        if (ord(k) in list_inquotes) and (inquotes == False):
            return (False, "Invalid symbol outside quotation marks")
        if ord(k) not in correct_list:
            errormsg = "Invalid symbol " + k
            return (False, errormsg)

    return (True, "")
