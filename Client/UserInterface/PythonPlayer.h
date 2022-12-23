		typedef struct SPartyMemberInfo
		{
			SPartyMemberInfo(DWORD _dwPID, const char * c_szName) : dwPID(_dwPID), strName(c_szName), dwVID(0), byState(0), byHPPercentage(0) { memset(&sAffects, 0, sizeof(sAffects)); } //@M2Fixme001
			DWORD dwVID;
			DWORD dwPID;
			std::string strName;
			BYTE byState;
			BYTE byHPPercentage;
			short sAffects[PARTY_AFFECT_SLOT_MAX_NUM];
		} TPartyMemberInfo;


//Search


		typedef struct SPartyMemberInfo
		{
#ifdef ENABLE_GET_PARTY_LEVEL
			SPartyMemberInfo(DWORD _dwPID, const char* c_szName, DWORD dwLevel) : dwPID(_dwPID), strName(c_szName), dwVID(0), byState(0), byHPPercentage(0), dwLevel(dwLevel) { memset(&sAffects, 0, sizeof(sAffects)); } //@M2Fixme001
#else
			SPartyMemberInfo(DWORD _dwPID, const char * c_szName) : dwPID(_dwPID), strName(c_szName), dwVID(0), byState(0), byHPPercentage(0) { memset(&sAffects, 0, sizeof(sAffects)); } //@M2Fixme001
#endif

			DWORD dwVID;
			DWORD dwPID;
			std::string strName;
			BYTE byState;
			BYTE byHPPercentage;
			short sAffects[PARTY_AFFECT_SLOT_MAX_NUM];
#ifdef ENABLE_GET_PARTY_LEVEL
			DWORD dwLevel;
#endif
		} TPartyMemberInfo;


//Change



void	AppendPartyMember(DWORD dwPID, const char * c_szName);


// Search

#ifdef ENABLE_GET_PARTY_LEVEL
		void	AppendPartyMember(DWORD dwPID, const char * c_szName, DWORD dwLevel);
#else
		void	AppendPartyMember(DWORD dwPID, const char * c_szName);
#endif


void	UpdatePartyMemberInfo(DWORD dwPID, BYTE byState, BYTE byHPPercentage);

// Search


#ifdef ENABLE_GET_PARTY_LEVEL
		void	UpdatePartyMemberInfo(DWORD dwPID, BYTE byState, BYTE byHPPercentage, DWORD dwLevel);
#else
		void	UpdatePartyMemberInfo(DWORD dwPID, BYTE byState, BYTE byHPPercentage);
#endif

//Change








