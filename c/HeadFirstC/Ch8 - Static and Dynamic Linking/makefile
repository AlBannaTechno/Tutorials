# using an archive library
# gcc -I./includes -c hfcal.c -o hfcal.o
# gcc -I./includes -c elliptical.c -o elliptical.o
# ar -rcs ./libs/libhfcal.a hfcal.o
# gcc elliptical.o -L./libs -lhfcal -o elliptical

# shared libraries work as followed:
# .so shared object : linux : normally stored in /usr/lib or /usr/local/lib
# .dll dynamic link libraries : windows : normally stored in the same directory
# .dylib dynamic libraries : mac : normally stored in /usr/lib or /usr/local/lib

# using a shared object
echo "US version"

gcc -I./includes -fPIC -c hfcal.c -o hfcal.o
gcc -shared hfcal.o -o ./libs/libhfcal.so # linux
# gcc -shared hfcal.o -o ./libs/libhfcal.dll # windows
gcc -I./includes -c elliptical.c -o elliptical.o
gcc elliptical.o -L./libs -lhfcal -o elliptical
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:./libs # linux
# PATH="%PATH%:./libs" # windows
./elliptical

echo -e "\nUK version"

# UK version
gcc -I./includes -fPIC -c hfcal_UK.c -o hfcal.o
gcc -shared hfcal.o -o ./libs/libhfcal.so
./elliptical
