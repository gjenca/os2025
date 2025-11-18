
def passwd_dict():

    ret={}
    with open('/etc/passwd') as f:
        for line in f:
            line=line.strip() # zmazeme biele znaky zo zaciatku a konca
            line_splitted=line.split(':')
            username=line_splitted[0]
            userid=line_splitted[2]
            ret[username]=userid
    return ret
