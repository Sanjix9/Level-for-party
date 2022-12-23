		def AddPartyMember(self, pid, name):
			self.interface.AddPartyMember(pid, name)


search

	if app.ENABLE_GET_PARTY_LEVEL:
		def AddPartyMember(self, pid, name, level):
			self.interface.AddPartyMember(pid, name, level)
	else:
		def AddPartyMember(self, pid, name):
			self.interface.AddPartyMember(pid, name)

change