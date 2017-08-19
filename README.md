# Signatumclassic Classic Skunk Hash Algorithm Official Launch on 10/08/2018

Fork Signatumclassic's Skunkhash Raptor Proof of Work Algorithm

Fixed Skunk Hash Module

Improve Performace of Signatumclassic-Classic's POW Algo 
---------------------------------------------------
Nvidia GPU Mining Effectioncy Improved by 10%
---------------------------------------------------
Improved Transaction Speed By 5% 
---------------------------------------------------
Increase POW Blocks to 1,000,000
---------------------------------------------------
                                                     
    int64_t GetProofOfWorkReward(int64_t nFees)  
    {                                            
    int64_t nSubsidy = 1 * COIN;                 
                                                 
    if(pindexBest->nHeight <= 100000) {          
        nSubsidy = 30 * COIN;                    
    } else if(pindexBest->nHeight <= 500000) {   
        nSubsidy = 15 * COIN;                    
    } else if(pindexBest->nHeight <= 1000000) {  
        nSubsidy = 7.5 * COIN;                   
    } else {                                     
        nSubsidy = 1 * COIN;                     
                                              
---------------------------------------------------

POS Will Start After Blocks 985,000

POS 5% Reward Per Annual 

Premined The First 1000 Blocks 

Official Release At Block 1001


# Signatumclassicclassic.conf
----------------------


	daemon=1
	server=1
	listen=1
	rpcuser=Your-User-Name
	rpcpassword=Your-Password
	rpcport=9998
	rpcallowip=127.0.0.1
	rpcallowip=You-Public-Ipaddress


--------------------------------

Instand Mine With Your Local Daemon p2p-Port: http://127.0.0.1:9999 Or http://Your-Lan-Ip-Address:9999 

# Build Dependencies
-----------------------------
For windows user, please follow this link "https://www.windowscentral.com/how-install-bash-shell-command-line-windows-10" to install ubuntu bash on windows 10 (only). After installed please follow linux guide !!!

	cd signatumclassicclassicd

	sudo sh build.sh install

# Compile signatumclassicclassicd
-------------------------

	cd src/leveldb

	chmod +x build_detect_platform

	make clean && make libleveldb.a libmemenv.a

	cd ../..

	make -f makefile.unix

# Compile Linux QT Wallet

	cd signatumclassicclassicd/

	qmake

	make 

# Windows Build Instructions
----------------------------

- Download the `QT Windows SDK`_ and install it. You don't need the Symbian stuff, just the desktop Qt.

- Compile openssl, boost and dbcxx.

- Open the .pro file in QT creator and build as normal (ctrl-B)

 _`QT Windows SDK`: http://qt-project.org/downloads

# Mac OS X
---------

- Download and install the `Qt Mac OS X SDK`_. It is recommended to also install Apple's Xcode with UNIX tools.

- Download and install `MacPorts`_.

- Execute the following commands in a terminal to get the dependencies:

sudo port selfupdate

sudo port install boost db48 miniupnpc

- Open the .pro file in Qt Creator and build as normal (cmd-B)

 _`Qt Mac OS X SDK`: http://qt-project.org/downloads

 _`MacPorts`: http://www.macports.org/install.php


# Signatumclassic Classic

# test
# signatumclassicclassicd
