import pprint
n = int(input())
langs = {}

for q in range(n):
    line = input()
    word, lang = "", ""

    for c in line:
        if (c >= 'a' and c <= 'z') or (c >= 'A' and c <= 'Z') or c == '-' or c == "'" or c == "’":
            word += (c if lang == "" else c.lower())
        else:
            if lang == "": lang = word
            else: langs[word.lower()] = lang
            word = ""
        
    if word != "":
        langs[word.lower()] = lang

end = False
while not end:
    try:
        line = input()
        word = ""
        for c in line:
            if (c >= 'a' and c <= 'z') or (c >= 'A' and c <= 'Z') or c == '-' or c == "'" or c == "’":
                word += c.lower()
            else:
                if word in list(langs):
                    print(langs[word])
                    word = ""
                    break
                word = ""

        if word != "":
            if word in list(langs):
                print(langs[word])

    except EOFError:
        end = True
