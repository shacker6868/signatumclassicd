#!/bin/bash

set -e

date


#################################################################
# Update Ubuntu and install prerequisites for running Signatumclassic   #
#################################################################
sudo apt-get update && sudo apt-get upgrade && sudo apt-get dist-upgrade
#################################################################
# Build Signatumclassic from source                                     #
#################################################################
NPROC=$(nproc)
echo "nproc: $NPROC"
#################################################################
# Install all necessary packages for building Signatumclassic           #
#################################################################
sudo apt-get install -y qt4-qmake libqt4-dev libminiupnpc-dev libdb++-dev libdb-dev libcrypto++-dev libqrencode-dev libboost-all-dev build-essential libboost-system-dev libboost-filesystem-dev libboost-program-options-dev libboost-thread-dev libboost-filesystem-dev libboost-program-options-dev libboost-thread-dev libssl-dev libdb++-dev libssl-dev ufw git build-essential libtool autotools-dev autoconf pkg-config libssl-dev libboost-all-dev 

sudo apt-get install qt5-default qt5-qmake qtbase5-dev-tools qttools5-dev-tools \
        build-essential libboost-dev libboost-system-dev \
        libboost-filesystem-dev libboost-program-options-dev libboost-thread-dev \
        libssl-dev libdb++-dev libminiupnpc-dev

sudo apt-get update

sudo apt-get install \
      build-essential pkg-config libc6-dev m4 g++-multilib \
      autoconf libtool ncurses-dev unzip git python \
      zlib1g-dev wget bsdmainutils automake

sudo add-apt-repository ppa:bitcoin/bitcoin

sudo apt-get update

sudo apt-get install -y libdb5.3-dev libdb5.3++-dev

sudo apt-get install libminiupnpc-dev 

sudo apt-get autoremove








