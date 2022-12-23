	if (GetParty() != NULL)
	{
		GetParty()->UpdateOfflineState(GetPlayerID());
	}

// search

	if (GetParty() != NULL)
	{
		GetParty()->UpdateOfflineState(GetPlayerID()
#ifdef ENABLE_GET_PARTY_LEVEL
			, this
#endif
		);
	}

// change


	out.role		= GetParty()->GetRole(GetPlayerID());

// search


// add after

#ifdef ENABLE_GET_PARTY_LEVEL
	out.dwLevel = GetLevel();
#endif







