typedef struct packet_party_add
{
    BYTE header;
    DWORD pid;
    char name[CHARACTER_NAME_MAX_LEN+1];
} TPacketGCPartyAdd;

typedef struct packet_party_update
{
    BYTE header;
    DWORD pid;
    BYTE state;
    BYTE percent_hp;
    short affects[PARTY_AFFECT_SLOT_MAX_NUM];
} TPacketGCPartyUpdate;


search change


typedef struct packet_party_add
{
    BYTE header;
    DWORD pid;
    char name[CHARACTER_NAME_MAX_LEN+1];
#ifdef ENABLE_GET_PARTY_LEVEL
	DWORD	dwLevel;
#endif
} TPacketGCPartyAdd;

typedef struct packet_party_update
{
    BYTE header;
    DWORD pid;
    BYTE state;
    BYTE percent_hp;
    short affects[PARTY_AFFECT_SLOT_MAX_NUM];
#ifdef ENABLE_GET_PARTY_LEVEL
	DWORD dwLevel;
#endif
} TPacketGCPartyUpdate;