typedef struct packet_party_add
{
	BYTE	header;
	DWORD	pid;
	char	name[CHARACTER_NAME_MAX_LEN+1];
} TPacketGCPartyAdd;

// search

typedef struct packet_party_add
{
	BYTE	header;
	DWORD	pid;
	char	name[CHARACTER_NAME_MAX_LEN+1];
#ifdef ENABLE_GET_PARTY_LEVEL
	DWORD	dwLevel;
#endif
} TPacketGCPartyAdd;

// change


typedef struct packet_party_update
{
	BYTE	header;
	DWORD	pid;
	BYTE	role;
	BYTE	percent_hp;
	short	affects[7];
} TPacketGCPartyUpdate;

// search

typedef struct packet_party_update
{
	BYTE	header;
	DWORD	pid;
	BYTE	role;
	BYTE	percent_hp;
	short	affects[7];
#ifdef ENABLE_GET_PARTY_LEVEL
	DWORD	dwLevel;
#endif
} TPacketGCPartyUpdate;

// change

