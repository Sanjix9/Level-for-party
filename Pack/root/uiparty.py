self.nameTextLine = self.GetChild("NamePrint") #@find 


#@add after
			if app.ENABLE_GET_PARTY_LEVEL:
				self.levelTextLine = self.GetChild("LevelPrint")

self.nameTextLine = None #@find 

#@add after

		if app.ENABLE_GET_PARTY_LEVEL:
			self.levelTextLine = None


	def SetCharacterPID(self, pid): #@find 
		self.pid = pid

#@add after

	if app.ENABLE_GET_PARTY_LEVEL:
		def SetCharacterLevel(self, level, pid):
			if pid == self.pid:
				if len(self.GetCharacterName()) > 0:
					self.levelTextLine.SetText("Lv.{} {}".format(level, self.GetCharacterName()))
					self.nameTextLine.Hide()
				else:
					self.levelTextLine.SetText("Lv.{}".format(level))
					self.nameTextLine.Show()



		self.nameTextLine.SetPackedFontColor(self.LINK_COLOR) #@find 

#@add after

		if app.ENABLE_GET_PARTY_LEVEL:
			self.levelTextLine.SetPackedFontColor(self.LINK_COLOR)

		self.nameTextLine.SetPackedFontColor(self.UNLINK_COLOR) #@find 

#@add after

		if app.ENABLE_GET_PARTY_LEVEL:
			self.levelTextLine.SetPackedFontColor(self.UNLINK_COLOR)


	def AddPartyMember(self, pid, name): #@find

		board = self.__FindPartyMemberInfoBoardByPID(pid)

		if None == board:

			board = PartyMemberInfoBoard()
			board.SetParent(self)
			board.SetCharacterPID(pid)

			self.partyMemberInfoBoardList.append(board)
			self.__ArrangePartyMemberInfoBoard()
			self.UpdateRect()

		if not name:
			name = localeInfo.PARTY_MEMBER_OFFLINE

		board.SetCharacterName(name)
		board.Unlink()

		self.Show()

#@Change



	if app.ENABLE_GET_PARTY_LEVEL:
		def AddPartyMember(self, pid, name, level):
			board = self.__FindPartyMemberInfoBoardByPID(pid)

			if None == board:

				board = PartyMemberInfoBoard()
				board.SetParent(self)
				board.SetCharacterPID(pid)
				board.SetCharacterLevel(level, pid)

				self.partyMemberInfoBoardList.append(board)
				self.__ArrangePartyMemberInfoBoard()
				self.UpdateRect()

			if not name:
				name = localeInfo.PARTY_MEMBER_OFFLINE

			board.SetCharacterName(name)
			board.Unlink()

			self.Show()
	else:
		def AddPartyMember(self, pid, name):

			board = self.__FindPartyMemberInfoBoardByPID(pid)

			if None == board:

				board = PartyMemberInfoBoard()
				board.SetParent(self)
				board.SetCharacterPID(pid)

				self.partyMemberInfoBoardList.append(board)
				self.__ArrangePartyMemberInfoBoard()
				self.UpdateRect()

			if not name:
				name = localeInfo.PARTY_MEMBER_OFFLINE

			board.SetCharacterName(name)
			board.Unlink()

			self.Show()


affectsList = player.GetPartyMemberAffects(pid) #@find

#@add after

		if app.ENABLE_GET_PARTY_LEVEL:
			level = player.GetPartyMemberLevel(pid)
			board.SetCharacterLevel(level, pid)
