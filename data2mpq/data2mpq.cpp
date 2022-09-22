#include <Windows.h>
#include <filesystem>
#include <iostream>
#include <cstdint>

#ifndef VERSION
#define VERSION '113c'
#endif

static  uint32_t GAME_EXE = (uint32_t)GetModuleHandle(NULL);
static  uint32_t DLLBASE_D2CLIENT = (uint32_t)LoadLibraryA("D2Client.dll");
static  uint32_t DLLBASE_D2COMMON = (uint32_t)LoadLibraryA("D2Common.dll");
static  uint32_t DLLBASE_D2LANG = (uint32_t)LoadLibraryA("D2Lang.dll");
static  uint32_t DLLBASE_D2WIN = (uint32_t)LoadLibraryA("D2Win.dll");
static  uint32_t DLLBASE_FOG = (uint32_t)LoadLibraryA("Fog.dll");
static  uint32_t DLLBASE_STORM = (uint32_t)LoadLibraryA("Storm.dll");

#pragma region Define PTRs 1.10f
#if VERSION=='110f'
// Function: FOG_InitLogManager
// Address: Fog_10021 (Fog.0x6FF5E1A0) (Relative: 0xE1A0)
typedef uint32_t __fastcall FOG_InitLogManager_t(const char* szLogName);
static FOG_InitLogManager_t* FOG_InitLogManager = reinterpret_cast<FOG_InitLogManager_t*>(DLLBASE_FOG + 0xE1A0);


// Function: FOG_MPQSetConfig
// Address: Fog_10101 (Fog.0x6FF61590) (Relative: 0x11590)
typedef BOOL __fastcall FOG_MPQSetConfig_t(int dwDirectAccessFlags, int bEnableSeekOptimization);
static FOG_MPQSetConfig_t* FOG_MPQSetConfig = reinterpret_cast<FOG_MPQSetConfig_t*>(DLLBASE_FOG + 0x11590);

// Function: FOG_10218
// Address: Fog_10218 (Fog.0x6FF5CC40) (Relative: 0xCC40)
typedef BOOL __fastcall FOG_10218_t();
static FOG_10218_t* FOG_10218_110f = reinterpret_cast<FOG_10218_t*>(DLLBASE_FOG + 0xCC40);

// Function: FOG_10089
// Address: Fog_10089 (Fog.0x6FF5C010) (Relative: 0xC010)
typedef void __fastcall FOG_10089_t(int32_t a1);
static FOG_10089_t* FOG_10089_110f = reinterpret_cast<FOG_10089_t*>(DLLBASE_FOG + 0xC010);


// Function: D2WIN_10037
// Address: D2Win_10037 (D2Win.0x6F8A5B60) (Relative: 0x5B60)
// Comment: Loads some MPQs
typedef BOOL __stdcall D2WIN_10037_t();
static D2WIN_10037_t* D2WIN_10037_110f = reinterpret_cast<D2WIN_10037_t*>(DLLBASE_D2WIN + 0x5B60);

// Function: D2WIN_10171
// Address: D2Win_10171 (D2Win.0x6F8A5E80) (Relative: 0x5E80)
// Comment: Loads some MPQs
typedef BOOL __fastcall D2WIN_10171_t(uint32_t a1, uint32_t a2, uint32_t a3, void* a4);
static D2WIN_10171_t* D2WIN_10171_110f = reinterpret_cast<D2WIN_10171_t*>(DLLBASE_D2WIN + 0x5E80);

// Function: D2LANG_10000
// Address: D2Lang_10000 (D2Lang.0x6FC12F90) (Relative: 0x2F90)
typedef int32_t __fastcall D2LANG_10000_t(int32_t a1, const char* a2, int32_t a3);
static D2LANG_10000_t* D2LANG_10000_110f = reinterpret_cast<D2LANG_10000_t*>(DLLBASE_D2LANG + 0x2F90);

// Function: DATATBLS_LoadAllTxts
// Address: D2Common_10576 (D2Common.0x6FD504B0) (Relative: 0x104B0)
typedef void __stdcall DATATBLS_LoadAllTxts_t(void* pMemPool, int a2, int a3);
static DATATBLS_LoadAllTxts_t* DATATBLS_LoadAllTxts = reinterpret_cast<DATATBLS_LoadAllTxts_t*>(DLLBASE_D2COMMON + 0x104B0);

static BOOL* p_bCompile = reinterpret_cast<BOOL*>(DLLBASE_D2COMMON + 0xaa28c);

static uint32_t* p_STORM_MPQHashTable = reinterpret_cast<uint32_t*>(DLLBASE_STORM + 0x3a29c);

#pragma pack(1)
struct D2Client_t
{
    uint32_t dwInit;        //0x00
    uint8_t _1[0x20C - 4];  //0x04
    uint32_t fpInit;        //0x20C
};
static D2Client_t D2Client;
static_assert(offsetof(D2Client_t, fpInit) == 0x20C);
#pragma pack()

#endif
#pragma endregion
#pragma region Define PTRs 1.13c
#if VERSION=='113c'
// Function: FOG_InitLogManager
// Address: Fog_10021 (Fog.0x6FF60810) (Relative: 0x10810)
typedef uint32_t __fastcall FOG_InitLogManager_t(const char* szLogName);
static FOG_InitLogManager_t* FOG_InitLogManager = reinterpret_cast<FOG_InitLogManager_t*>(DLLBASE_FOG + 0x10810);

// Function: FOG_MPQSetConfig
// Address: Fog_10101 (Fog.0x6FF67EF0) (Relative: 0x17EF0)
typedef BOOL __fastcall FOG_MPQSetConfig_t(int dwDirectAccessFlags, int bEnableSeekOptimization);
static FOG_MPQSetConfig_t* FOG_MPQSetConfig = reinterpret_cast<FOG_MPQSetConfig_t*>(DLLBASE_FOG + 0x17EF0);

// Function: FOG_10218
// Address: Fog_10218 (Fog.0x6FF6F550) (Relative: 0x1F550)
typedef BOOL __fastcall FOG_10218_t();
static FOG_10218_t* FOG_10218_110f = reinterpret_cast<FOG_10218_t*>(DLLBASE_FOG + 0x1F550);

// Function: FOG_10089
// Address: Fog_10089 (Fog.0x6FF6DF00) (Relative: 0x1DF00)
typedef void __fastcall FOG_10089_t(int32_t a1);
static FOG_10089_t* FOG_10089_110f = reinterpret_cast<FOG_10089_t*>(DLLBASE_FOG + 0x1DF00);


// Function: D2WIN_10086
// Address: D2Win_10086 (D2Win.0x6F8EAA20) (Relative: 0xAA20)
// Comment: Loads some MPQs
typedef BOOL __stdcall D2WIN_10037_t();
static D2WIN_10037_t* D2WIN_10037_110f = reinterpret_cast<D2WIN_10037_t*>(DLLBASE_D2WIN + 0xAA20);

// Function: D2WIN_10005
// Address: D2Win_10005 (D2Win.0x6F8EA890) (Relative: 0xA890)
// Comment: Loads some MPQs
typedef BOOL __fastcall D2WIN_10171_t(uint32_t a1, uint32_t a2, uint32_t a3, void* a4);
static D2WIN_10171_t* D2WIN_10171_110f = reinterpret_cast<D2WIN_10171_t*>(DLLBASE_D2WIN + 0xA890);

// Function: D2LANG_10008
// Address: D2Lang_10008 (D2Lang.0x6FC0A130) (Relative: 0xA130)
typedef int32_t __fastcall D2LANG_10000_t(int32_t a1, const char* a2, int32_t a3);
static D2LANG_10000_t* D2LANG_10000_110f = reinterpret_cast<D2LANG_10000_t*>(DLLBASE_D2LANG + 0xA130);

// Function: DATATBLS_LoadAllTxts
// Address: D2Common_10943 (D2Common.0x6FDB6160) (Relative: 0x66160)
typedef void __stdcall DATATBLS_LoadAllTxts_t(void* pMemPool, int a2, int a3);
static DATATBLS_LoadAllTxts_t* DATATBLS_LoadAllTxts = reinterpret_cast<DATATBLS_LoadAllTxts_t*>(DLLBASE_D2COMMON + 0x66160);

static BOOL* p_bCompile = reinterpret_cast<BOOL*>(DLLBASE_D2COMMON + 0xa145c);

static uint32_t* p_STORM_MPQHashTable = reinterpret_cast<uint32_t*>(DLLBASE_STORM + 0x53120);

#pragma pack(1)
struct D2Client_t
{
    uint32_t dwInit;        //0x00
    uint8_t _1[0x20D - 4];  //0x04
    uint32_t fpInit;        //0x20D
};
static D2Client_t D2Client;
static_assert(offsetof(D2Client_t, fpInit) == 0x20D);
#pragma pack()

#endif
#pragma endregion


static uint32_t D2ClientInterface() {
    return D2Client.dwInit;
}

int main()
{
#pragma region Compile TXTs
    //Compile TXTs
    * p_STORM_MPQHashTable = 0;
    D2Client.dwInit = 1;
    D2Client.fpInit = (uint32_t)D2ClientInterface;

    FOG_InitLogManager("D2");
    FOG_MPQSetConfig(1, 0);
    FOG_10089_110f(1);
    FOG_10218_110f();
    D2WIN_10037_110f();
    D2WIN_10171_110f(0, 0, 0, &D2Client);
    D2LANG_10000_110f(0, "ENG", 0);

    *p_bCompile = 1;
    DATATBLS_LoadAllTxts(0, 0, 0);
#pragma endregion
#pragma region Write BINs + Other Files into Patch_D2.mpq

#pragma endregion

    std::cout << "Hello World!\n";
}


