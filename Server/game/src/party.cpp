void CPartyManager::P2PLogin(DWORD pid, const char* name)
{
	auto it = m_map_pkParty.find(pid);

	if (it == m_map_pkParty.end())
		return;
	it->second->UpdateOnlineState(pid, name);
}
void CPartyManager::P2PLogout(DWORD pid)
{
	auto it = m_map_pkParty.find(pid);

	if (it == m_map_pkParty.end())
		return;
	it->second->UpdateOfflineState(pid);
}

// search

void CPartyManager::P2PLogin(DWORD pid, const char* name)
{
	auto it = m_map_pkParty.find(pid);

	if (it == m_map_pkParty.end())
		return;

#ifdef ENABLE_GET_PARTY_LEVEL
	LPCHARACTER ch = CHARACTER_MANAGER::instance().FindByPID(pid);
	it->second->UpdateOnlineState(pid, name, ch);
#else
	it->second->UpdateOnlineState(pid, name);
#endif
}
void CPartyManager::P2PLogout(DWORD pid)
{
	auto it = m_map_pkParty.find(pid);

	if (it == m_map_pkParty.end())
		return;
#ifdef ENABLE_GET_PARTY_LEVEL
	LPCHARACTER ch = CHARACTER_MANAGER::instance().FindByPID(pid);
	it->second->UpdateOfflineState(pid, ch);
#else
	it->second->UpdateOfflineState(pid);
#endif
}

// change


Member.strName = ch->GetName();

// search

#ifdef ENABLE_GET_PARTY_LEVEL
				Member.dwLevel = ch->GetLevel();
#endif

// add after


		if (m_bPCParty)
		{
			CPartyManager::instance().SetPartyMember(dwPID, this);
			SendPartyJoinOneToAll(dwPID);

			LPCHARACTER ch = CHARACTER_MANAGER::instance().FindByPID(dwPID);

			if (ch)
				SendParameter(ch);
		}


// search


		if (m_bPCParty)
		{
			CPartyManager::instance().SetPartyMember(dwPID, this);
			LPCHARACTER ch = CHARACTER_MANAGER::instance().FindByPID(dwPID);

			SendPartyJoinOneToAll(dwPID
#ifdef ENABLE_GET_PARTY_LEVEL
				,ch
#endif
			);

			if (ch)
				SendParameter(ch);
		}

// change





SendPartyJoinOneToAll(pkChr->GetPlayerID());

// search


#ifdef ENABLE_GET_PARTY_LEVEL
		it->second.dwLevel = pkChr->GetLevel();
		SendPartyJoinOneToAll(pkChr->GetPlayerID(), pkChr);
#else
		SendPartyJoinOneToAll(pkChr->GetPlayerID());
#endif

// change




void CParty::SendPartyJoinOneToAll(DWORD pid)
{
	const TMember& r = m_memberMap[pid];

	TPacketGCPartyAdd p;

	p.header = HEADER_GC_PARTY_ADD;
	p.pid = pid;
	strlcpy(p.name, r.strName.c_str(), sizeof(p.name));

	for (auto it = m_memberMap.begin(); it != m_memberMap.end(); ++it)
	{
		if (it->second.pCharacter && it->second.pCharacter->GetDesc())
			it->second.pCharacter->GetDesc()->Packet(&p, sizeof(p));
	}
}

void CParty::SendPartyJoinAllToOne(LPCHARACTER ch)
{
	if (!ch->GetDesc())
		return;

	TPacketGCPartyAdd p;

	p.header = HEADER_GC_PARTY_ADD;
	p.name[CHARACTER_NAME_MAX_LEN] = '\0';

	for (auto it = m_memberMap.begin();it!= m_memberMap.end(); ++it)
	{
		p.pid = it->first;
		strlcpy(p.name, it->second.strName.c_str(), sizeof(p.name));
		ch->GetDesc()->Packet(&p, sizeof(p));
	}
}


// search






void CParty::SendPartyJoinOneToAll(DWORD pid
#ifdef ENABLE_GET_PARTY_LEVEL
	, LPCHARACTER ch
#endif
)
{
	const TMember& r = m_memberMap[pid];

	TPacketGCPartyAdd p;

	p.header = HEADER_GC_PARTY_ADD;
	p.pid = pid;
	strlcpy(p.name, r.strName.c_str(), sizeof(p.name));
#ifdef ENABLE_GET_PARTY_LEVEL
	p.dwLevel = ch ? ch->GetLevel() : 10;
#endif

	for (auto it = m_memberMap.begin(); it != m_memberMap.end(); ++it)
	{
		if (it->second.pCharacter && it->second.pCharacter->GetDesc())
			it->second.pCharacter->GetDesc()->Packet(&p, sizeof(p));
	}
}

void CParty::SendPartyJoinAllToOne(LPCHARACTER ch)
{
	if (!ch->GetDesc())
		return;

	TPacketGCPartyAdd p;

	p.header = HEADER_GC_PARTY_ADD;
	p.name[CHARACTER_NAME_MAX_LEN] = '\0';
#ifdef ENABLE_GET_PARTY_LEVEL
	p.dwLevel = 1;
#endif

	for (auto it = m_memberMap.begin();it!= m_memberMap.end(); ++it)
	{
		p.pid = it->first;
		strlcpy(p.name, it->second.strName.c_str(), sizeof(p.name));
#ifdef ENABLE_GET_PARTY_LEVEL
		p.dwLevel = it->second.dwLevel;
#endif
		ch->GetDesc()->Packet(&p, sizeof(p));
	}
}


// change




void CParty::SendPartyInfoOneToAll(DWORD pid)
{
	auto it = m_memberMap.find(pid);

	if (it == m_memberMap.end())
		return;

	if (it->second.pCharacter)
	{
		SendPartyInfoOneToAll(it->second.pCharacter);
		return;
	}

	// Data Building
	TPacketGCPartyUpdate p;
	memset(&p, 0, sizeof(p));
	p.header = HEADER_GC_PARTY_UPDATE;
	p.pid = pid;
	p.percent_hp = 255;
	p.role = it->second.bRole;

	for (it = m_memberMap.begin();it!= m_memberMap.end(); ++it)
	{
		if ((it->second.pCharacter) && (it->second.pCharacter->GetDesc()))
		{
			//sys_log(2, "PARTY send info %s[%d] to %s[%d]", ch->GetName(), (DWORD)ch->GetVID(), it->second.pCharacter->GetName(), (DWORD)it->second.pCharacter->GetVID());
			it->second.pCharacter->GetDesc()->Packet(&p, sizeof(p));
		}
	}
}


// search



void CParty::SendPartyInfoOneToAll(DWORD pid)
{
	auto it = m_memberMap.find(pid);

	if (it == m_memberMap.end())
		return;

	if (it->second.pCharacter)
	{
		SendPartyInfoOneToAll(it->second.pCharacter);
		return;
	}

	// Data Building
	TPacketGCPartyUpdate p;
	memset(&p, 0, sizeof(p));
	p.header = HEADER_GC_PARTY_UPDATE;
	p.pid = pid;
	p.percent_hp = 255;
	p.role = it->second.bRole;
#ifdef ENABLE_GET_PARTY_LEVEL
	LPCHARACTER ch = CHARACTER_MANAGER::instance().FindByPID(pid);
	p.dwLevel = ch ? ch->GetLevel() : it->second.dwLevel;
#endif

	for (it = m_memberMap.begin();it!= m_memberMap.end(); ++it)
	{
		if ((it->second.pCharacter) && (it->second.pCharacter->GetDesc()))
		{
			//sys_log(2, "PARTY send info %s[%d] to %s[%d]", ch->GetName(), (DWORD)ch->GetVID(), it->second.pCharacter->GetName(), (DWORD)it->second.pCharacter->GetVID());
			it->second.pCharacter->GetDesc()->Packet(&p, sizeof(p));
		}
	}
}


// change




void CParty::SendPartyInfoAllToOne(LPCHARACTER ch)
{
	TPacketGCPartyUpdate p;

	for (auto it = m_memberMap.begin(); it != m_memberMap.end(); ++it)
	{
		if (!it->second.pCharacter)
		{
			DWORD pid = it->first;
			memset(&p, 0, sizeof(p));
			p.header = HEADER_GC_PARTY_UPDATE;
			p.pid = pid;
			p.percent_hp = 255;
			p.role = it->second.bRole;
			ch->GetDesc()->Packet(&p, sizeof(p));
			continue;
		}

		it->second.pCharacter->BuildUpdatePartyPacket(p);
		sys_log(2, "PARTY send info %s[%d] to %s[%d]", it->second.pCharacter->GetName(), (DWORD)it->second.pCharacter->GetVID(), ch->GetName(), (DWORD)ch->GetVID());
		ch->GetDesc()->Packet(&p, sizeof(p));
	}
}

// search


void CParty::SendPartyInfoAllToOne(LPCHARACTER ch)
{
	TPacketGCPartyUpdate p;

	for (auto it = m_memberMap.begin(); it != m_memberMap.end(); ++it)
	{
		if (!it->second.pCharacter)
		{
			DWORD pid = it->first;
			memset(&p, 0, sizeof(p));
			p.header = HEADER_GC_PARTY_UPDATE;
			p.pid = pid;
			p.percent_hp = 255;
			p.role = it->second.bRole;
#ifdef ENABLE_GET_PARTY_LEVEL
			DWORD dwLevel = it->second.dwLevel;
			p.dwLevel = dwLevel;
#endif
			ch->GetDesc()->Packet(&p, sizeof(p));
			continue;
		}

		it->second.pCharacter->BuildUpdatePartyPacket(p);
		sys_log(2, "PARTY send info %s[%d] to %s[%d]", it->second.pCharacter->GetName(), (DWORD)it->second.pCharacter->GetVID(), ch->GetName(), (DWORD)ch->GetVID());
		ch->GetDesc()->Packet(&p, sizeof(p));
	}
}

// change













void CParty::UpdateOnlineState(DWORD dwPID, const char* name)
{
	TMember& r = m_memberMap[dwPID];

	TPacketGCPartyAdd p;

	p.header = HEADER_GC_PARTY_ADD;
	p.pid = dwPID;
	r.strName = name;
	strlcpy(p.name, name, sizeof(p.name));

	for (auto it = m_memberMap.begin(); it != m_memberMap.end(); ++it)
	{
		if (it->second.pCharacter && it->second.pCharacter->GetDesc())
			it->second.pCharacter->GetDesc()->Packet(&p, sizeof(p));
	}
}
void CParty::UpdateOfflineState(DWORD dwPID)
{

	TPacketGCPartyAdd p;
	p.header = HEADER_GC_PARTY_ADD;
	p.pid = dwPID;
	memset(p.name, 0, CHARACTER_NAME_MAX_LEN+1);

	for (auto it = m_memberMap.begin(); it != m_memberMap.end(); ++it)
	{
		if (it->second.pCharacter && it->second.pCharacter->GetDesc())
			it->second.pCharacter->GetDesc()->Packet(&p, sizeof(p));
	}
}


// search


void CParty::UpdateOnlineState(DWORD dwPID, const char* name
#ifdef ENABLE_GET_PARTY_LEVEL
	, LPCHARACTER ch
#endif
)
{
	TMember& r = m_memberMap[dwPID];

	TPacketGCPartyAdd p;

	p.header = HEADER_GC_PARTY_ADD;
	p.pid = dwPID;
	r.strName = name;
	strlcpy(p.name, name, sizeof(p.name));
#ifdef ENABLE_GET_PARTY_LEVEL
	r.dwLevel = ch ? ch->GetLevel() : 90;
	p.dwLevel = ch ? ch->GetLevel() : 40;
#endif

	for (auto it = m_memberMap.begin(); it != m_memberMap.end(); ++it)
	{
		if (it->second.pCharacter && it->second.pCharacter->GetDesc())
			it->second.pCharacter->GetDesc()->Packet(&p, sizeof(p));
	}
}
void CParty::UpdateOfflineState(DWORD dwPID
#ifdef ENABLE_GET_PARTY_LEVEL
	, LPCHARACTER ch
#endif
)
{
#ifdef ENABLE_GET_PARTY_LEVEL
	TMember& r = m_memberMap[dwPID];
#endif

	TPacketGCPartyAdd p;
	p.header = HEADER_GC_PARTY_ADD;
	p.pid = dwPID;
	memset(p.name, 0, CHARACTER_NAME_MAX_LEN+1);
#ifdef ENABLE_GET_PARTY_LEVEL
	r.dwLevel = ch ? ch->GetLevel() : 41;
	p.dwLevel = ch ? ch->GetLevel() : 92;
#endif

	for (auto it = m_memberMap.begin(); it != m_memberMap.end(); ++it)
	{
		if (it->second.pCharacter && it->second.pCharacter->GetDesc())
			it->second.pCharacter->GetDesc()->Packet(&p, sizeof(p));
	}
}



// change































