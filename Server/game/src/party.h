			std::string strName;

// search

#ifdef ENABLE_GET_PARTY_LEVEL
			DWORD	dwLevel;
#endif

// add after


		void		UpdateOnlineState(DWORD dwPID, const char* name);
		void		UpdateOfflineState(DWORD dwPID);
// search
		void		UpdateOnlineState(DWORD dwPID, const char* name
#ifdef ENABLE_GET_PARTY_LEVEL
			, LPCHARACTER ch
#endif
		);
		void		UpdateOfflineState(DWORD dwPID
#ifdef ENABLE_GET_PARTY_LEVEL
			, LPCHARACTER ch
#endif
		);
// change


		void		SendPartyJoinOneToAll(DWORD dwPID);

// search

		void		SendPartyJoinOneToAll(DWORD dwPID
#ifdef ENABLE_GET_PARTY_LEVEL
			, LPCHARACTER ch
#endif
		);

// change