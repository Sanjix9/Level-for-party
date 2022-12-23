void CPythonPlayer::AppendPartyMember(DWORD dwPID, const char * c_szName)
{
	m_PartyMemberMap.insert(std::make_pair(dwPID, TPartyMemberInfo(dwPID, c_szName)));
}

// search


#ifdef ENABLE_GET_PARTY_LEVEL
void CPythonPlayer::AppendPartyMember(DWORD dwPID, const char * c_szName, DWORD dwLevel)
{
	m_PartyMemberMap.insert(std::make_pair(dwPID, TPartyMemberInfo(dwPID, c_szName, dwLevel)));
}
#else
void CPythonPlayer::AppendPartyMember(DWORD dwPID, const char * c_szName)
{
	m_PartyMemberMap.insert(std::make_pair(dwPID, TPartyMemberInfo(dwPID, c_szName)));
}
#endif

// change


void CPythonPlayer::UpdatePartyMemberInfo(DWORD dwPID, BYTE byState, BYTE byHPPercentage)
{
	TPartyMemberInfo * pPartyMemberInfo;
	if (!GetPartyMemberPtr(dwPID, &pPartyMemberInfo))
	{
		TraceError(" CPythonPlayer::UpdatePartyMemberInfo(dwPID=%d, byState=%d, byHPPercentage=%d) - Failed to find character", dwPID, byState, byHPPercentage);
		return;
	}

	pPartyMemberInfo->byState = byState;
	pPartyMemberInfo->byHPPercentage = byHPPercentage;
}

// search



void CPythonPlayer::UpdatePartyMemberInfo(DWORD dwPID, BYTE byState, BYTE byHPPercentage
#ifdef ENABLE_GET_PARTY_LEVEL
	, DWORD dwLevel
#endif
	)
{
	TPartyMemberInfo * pPartyMemberInfo;
	if (!GetPartyMemberPtr(dwPID, &pPartyMemberInfo))
	{
		TraceError(" CPythonPlayer::UpdatePartyMemberInfo(dwPID=%d, byState=%d, byHPPercentage=%d) - Failed to find character", dwPID, byState, byHPPercentage);
		return;
	}

	pPartyMemberInfo->byState = byState;
	pPartyMemberInfo->byHPPercentage = byHPPercentage;
#ifdef ENABLE_GET_PARTY_LEVEL
	pPartyMemberInfo->dwLevel = dwLevel;
#endif
}

// change