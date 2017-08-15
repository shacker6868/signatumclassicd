// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2012 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "assert.h"

#include "chainparams.h"
#include "main.h"
#include "util.h"

#include <boost/assign/list_of.hpp>

using namespace boost::assign;

struct SeedSpec6 {
    uint8_t addr[16];
    uint16_t port;
};

#include "chainparamsseeds.h"


/////////////////
//Main network//
////////////////


static void convertSeed6(std::vector<CAddress> &vSeedsOut, const SeedSpec6 *data, unsigned int count)
{
   
    const int64_t nOneWeek = 7*24*60*60;
    for (unsigned int i = 0; i < count; i++)
    {
        struct in6_addr ip;
        memcpy(&ip, data[i].addr, sizeof(ip));
        CAddress addr(CService(ip, data[i].port));
        addr.nTime = GetTime() - GetRand(nOneWeek) - nOneWeek;
        vSeedsOut.push_back(addr);
    }
}

class CMainParams : public CChainParams {
public:
    CMainParams() {
        pchMessageStart[0] = 0xa6;
        pchMessageStart[1] = 0xf8;
        pchMessageStart[2] = 0xa6;
        pchMessageStart[3] = 0x78;
        vAlertPubKey = ParseHex("0486cce1bac0d543f104cbff2bd23680056a3b9ea05e1137d2ff90eeb5e08472eb500322593a2cb06fbf8297d7beb6cd30cb90f98153b5b7cce1493749e41e0284");
        nDefaultPort = 9999;
        nRPCPort = 9998;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 20);

        const char* pszTimestamp = "Signatum classic OFFICIAL LAUNCHING ON 10/08/2017";
        std::vector<CTxIn> vin;
        vin.resize(1);
        vin[0].scriptSig = CScript() << 0 << CBigNum(42) << vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
        std::vector<CTxOut> vout;
        vout.resize(1);
        vout[0].SetEmpty();
        CTransaction txNew(1, 1502198497, vin, vout, 0);
        genesis.vtx.push_back(txNew);
        genesis.hashPrevBlock = 0;
        genesis.hashMerkleRoot = genesis.BuildMerkleTree();
        genesis.nVersion = 1;
        genesis.nTime    = 1502198497;
        genesis.nBits    = bnProofOfWorkLimit.GetCompact();
        genesis.nNonce   = 1896426;

        hashGenesisBlock = genesis.GetHash();
        assert(hashGenesisBlock == uint256("0x00000e76a978caa31d1fb08ba505defda2f0463f48bc57315dbabb655a93be1e"));
        assert(genesis.hashMerkleRoot == uint256("0xdaf104a42a601001105c1d515568b9868f83e24bd42808e3d3ffb4132bb8e625"));

        

        vSeeds.push_back(CDNSSeedData("211.28.146.48", "108.61.185.25"));
	vSeeds.push_back(CDNSSeedData("pool.minertopia.org", "45.76.149.228"));
	vSeeds.push_back(CDNSSeedData("74.208.43.97", "74.208.166.29"));
    

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 25);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 125);
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1, (63+128));
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x02)(0x58)(0xC2)(0x1A).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x04)(0x86)(0xB6)(0xDD).convert_to_container<std::vector<unsigned char> >();

        convertSeed6(vFixedSeeds, pnSeed6_main, ARRAYLEN(pnSeed6_main));

        nLastPOWBlock = 1000000;
        nPOSStartBlock = 985000;
    }

    virtual const CBlock& GenesisBlock() const { return genesis; }
    virtual Network NetworkID() const { return CChainParams::MAIN; }

    virtual const vector<CAddress>& FixedSeeds() const {
        return vFixedSeeds;
    }
protected:
    CBlock genesis;
    vector<CAddress> vFixedSeeds;
};
static CMainParams mainParams;


////////////
//Testnet//
///////////

class CTestNetParams : public CMainParams {
public:
    CTestNetParams() {
        pchMessageStart[0] = 0x68;
        pchMessageStart[1] = 0x35;
        pchMessageStart[2] = 0x28;
        pchMessageStart[3] = 0x61;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 16);
        vAlertPubKey = ParseHex("0471dc165db490094d35cde15b1f5d755fa6ad6f2b5ed0f340e3f17f57389c3c2af113a8cbcc885bde73305a553b5640c83021128008ddf882e856336269080496");
        nDefaultPort = 26868;
        nRPCPort = 26969;

        strDataDir = "testnet";
       
        genesis.nBits  = bnProofOfWorkLimit.GetCompact();
        genesis.nNonce = 0;
        genesis.nTime    = 1502198497;
  
        hashGenesisBlock = genesis.GetHash();
         
        //assert(hashGenesisBlock == uint256("0x"));

        vFixedSeeds.clear();
        vSeeds.clear();
        vSeeds.push_back(CDNSSeedData("107.22.138.243", "107.22.138.243"));

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 65); 
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 196);
        base58Prefixes[SECRET_KEY]     = std::vector<unsigned char>(1, 65 + 128);
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x04)(0x35)(0x87)(0xCF).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x04)(0x35)(0x83)(0x94).convert_to_container<std::vector<unsigned char> >();

        convertSeed6(vFixedSeeds, pnSeed6_test, ARRAYLEN(pnSeed6_test));

        nLastPOWBlock = 0x7fffffff;
    }
    virtual Network NetworkID() const { return CChainParams::TESTNET; }
};
static CTestNetParams testNetParams;


///////////////////
//Regression test//
//////////////////
class CRegTestParams : public CTestNetParams {
public:
    CRegTestParams() {
        pchMessageStart[0] = 0xf6;
        pchMessageStart[1] = 0xb6;
        pchMessageStart[2] = 0xb6;
        pchMessageStart[3] = 0xd6;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 1);
        genesis.nTime = 1502198497;
        genesis.nBits  = bnProofOfWorkLimit.GetCompact();
        genesis.nNonce = 0;
        hashGenesisBlock = genesis.GetHash();
        nDefaultPort = 18444;
        strDataDir = "regtest";

        //MineGenesis(genesis);

        //assert(hashGenesisBlock == uint256("0x0000084215677b959303b4f774ddcc8a1bdc46b7b38cdcf59d9b9e4885c79aab"));

        vSeeds.clear();  // Regtest mode doesn't have any DNS seeds.
    }

    virtual bool RequireRPCPassword() const { return false; }
    virtual Network NetworkID() const { return CChainParams::REGTEST; }
};
static CRegTestParams regTestParams;

static CChainParams *pCurrentParams = &mainParams;

const CChainParams &Params() {
    return *pCurrentParams;
}

void SelectParams(CChainParams::Network network) {
    switch (network) {
        case CChainParams::MAIN:
            pCurrentParams = &mainParams;
            break;
        case CChainParams::TESTNET:
            pCurrentParams = &testNetParams;
            break;
        case CChainParams::REGTEST:
            pCurrentParams = &regTestParams;
            break;
        default:
            assert(false && "Unimplemented network");
            return;
    }
}

bool SelectParamsFromCommandLine() {
    bool fRegTest = GetBoolArg("-regtest", false);
    bool fTestNet = GetBoolArg("-testnet", false);

    if (fTestNet && fRegTest) {
        return false;
    }

    if (fRegTest) {
        SelectParams(CChainParams::REGTEST);
    } else if (fTestNet) {
        SelectParams(CChainParams::TESTNET);
    } else {
        SelectParams(CChainParams::MAIN);
    }
    return true;
}
