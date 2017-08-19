#!/bin/bash

set -e

date

#################################################################
# Update Ubuntu and install prerequisites for running Signatumclassic   #
#################################################################
sudo apt-get update
#################################################################
# Build Signatumclassic from source                                     #
#################################################################
NPROC=$(nproc)
echo "nproc: $NPROC"
#################################################################
# Install all necessary packages for building Signatumclassic           #
#################################################################
sudo apt-get install -y qt4-qmake libqt4-dev libminiupnpc-dev libdb++-dev libdb-dev libcrypto++-dev libqrencode-dev libboost-all-dev build-essential libboost-system-dev libboost-filesystem-dev libboost-program-options-dev libboost-thread-dev libboost-filesystem-dev libboost-program-options-dev libboost-thread-dev libssl-dev libdb++-dev libssl-dev ufw git
sudo add-apt-repository -y ppa:bitcoin/bitcoin
sudo apt-get update
sudo apt-get install -y libdb4.8-dev libdb4.8++-dev

# By default, assume running within repo
repo=$(pwd)
file=$repo/src/signatumclassicd
if [ ! -e "$file" ]; then
	# Now assume running outside and repo has been downloaded and named signatumclassic
	if [ ! -e "$repo/signatumclassic/build.sh" ]; then
		# if not, download the repo and name it signatumclassic
		git clone https://github.com/signatumclassicd/source signatumclassic
	fi
	repo=$repo/signatumclassic
	file=$repo/src/signatumclassicd
	cd $repo/src/
fi
make -j$NPROC -f makefile.unix

cp $repo/src/signatumclassicd /usr/bin/signatumclassicd

################################################################
# Configure to auto start at boot                                      #
################################################################
file=$HOME/.signatumclassic
if [ ! -e "$file" ]
then
        mkdir $HOME/.signatumclassic
fi
printf '%s\n%s\n%s\n%s\n' 'daemon=1' 'server=1' 'rpcuser=u' 'rpcpassword=p' | tee $HOME/.signatumclassic/signatumclassic.conf
file=/etc/init.d/signatumclassic
if [ ! -e "$file" ]
then
        printf '%s\n%s\n' '#!/bin/sh' 'sudo signatumclassicd' | sudo tee /etc/init.d/signatumclassic
        sudo chmod +x /etc/init.d/signatumclassic
        sudo update-rc.d signatumclassic defaults
fi

/usr/bin/signatumclassicd
echo "Signatumclassic has been setup successfully and is running..."

