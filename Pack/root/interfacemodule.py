search

		def AddPartyMember(self, pid, name):
			self.wndParty.AddPartyMember(pid, name)

			self.__ArrangeQuestButton()

change

	if app.ENABLE_GET_PARTY_LEVEL:
		def AddPartyMember(self, pid, name, level):
			self.wndParty.AddPartyMember(pid, name, level)

			self.__ArrangeQuestButton()
	else:
		def AddPartyMember(self, pid, name):
			self.wndParty.AddPartyMember(pid, name)

			self.__ArrangeQuestButton()