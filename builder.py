# -------------------------
# Cmake Project Template 
# Build Script Helper
# -------------------------
import argparse
import subprocess
import sys

numOpts = 5 
optMessage = """Choose Build Option:
   1) MacOS
   2) Windows
   3) IOS
   4) Android
   5) Web (WASM)
"""
pathToBrowser = "/Applications/Microsoft Edge.app/Contents/MacOS/Microsoft Edge"
Release = "-DCMAKE_BUILD_TYPE=Release"
Debug = "-DCMAKE_BUILD_TYPE=Debug"

def main():
    choice = None

    if (len(sys.argv) > 1 and sys.argv[1].isdigit()):
        choice = sys.argv[1]
    else:
        print(optMessage)
        while (True):
            choice = input(""); 
            if (choice.isdigit() and int(choice) in range(1, numOpts+1)):
                break
            
            print(f'\r\033[A')

    if (choice == "1"):
        print("MacOS")
        subprocess.run(["cmake", Debug, "-S", "./", "-B", "out/build"]) 
        subprocess.run(["make", "-C", "out/build"])
        subprocess.run(["make", "install", "-C", "out/build"])
    elif (choice == "2"):
        print("Windows")
    elif (choice == "3"):
        print("IOS")
    elif (choice == "4"):
        print("Android")
    elif (choice == "5"):
        print("Web (WASM)")
        subprocess.run(["emcmake", "cmake", Debug, "-S", "./", "-B", "out/build"])
        subprocess.run(["make", "-C", "build"])
        subprocess.run(["make", "install", "-C", "out/build"])
        subprocess.run(["emrun", "out/build/src/app.html", "--browser", pathToBrowser])
    else:
        print("Invalid Choice")

if __name__ == "__main__":
    main()
