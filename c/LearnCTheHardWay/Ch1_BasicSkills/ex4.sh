# 1) Download it 
curl -O http://valgrind.org/downloads/valgrind-3.6.1.tar.bz2

# 2) use md5sum to make sure it matches the one on the site
md5sum valgrind-3.6.1.tar.bz2

# 3) cd into the newly created directory
cd valgrind-3.6.1

# 4) configure it
./configure

# 5) install it (requires root)
sudo make install