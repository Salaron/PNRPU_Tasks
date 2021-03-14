import glob, codecs
import os  
import chardet

def updateEncoding(srcfile, trgfile):
    try:
        # open file and read bytes to check encoding
        with open(srcfile, "rb") as f:
            encoding = chardet.detect(f.read())["encoding"]
        if not encoding or encoding.lower().find("utf-8") != -1:
            return
        # if encoding is not uf8 then convert it
        with codecs.open(srcfile, 'r', encoding="cp1251") as f, codecs.open(trgfile, 'w', encoding='utf-8') as e:
            text = f.read()
            e.write(text)

        os.remove(srcfile) # remove old encoding file
        os.rename(trgfile, srcfile) # rename new encoding
    except UnicodeDecodeError:
        print('Decode Error')
    except UnicodeEncodeError:
        print('Encode Error')
        
def removeJunk(srcfile):
    with open(srcfile, "r+", encoding="utf-8") as f:
        result = []
        content = f.readlines()
        restricted = ["windows.h", "CP_UTF8", "system", "setlocale"]
        for line in content:
            if not any(r in line for r in restricted):
                result.append(line)
            if len(result) > 2 and result[len(result) - 2].find("int main") != -1 and line.find("{") != -1 or line.find("int main() {") != -1:
                result.append('\tsystem("chcp 1251>nul");\n')
        f.seek(0)
        f.truncate(0)
        f.write("".join(result))
        
# source files + markdown + text
files = glob.glob("./**/*.cpp", recursive=True) + glob.glob("./**/*.md", recursive=True) + glob.glob("./**/*.txt", recursive=True)
for f in files:
    print(f)
    updateEncoding(f, f + ".tmp")
    removeJunk(f)