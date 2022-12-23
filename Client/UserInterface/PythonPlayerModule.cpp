void initPlayer()

// search 

// before add

#ifdef ENABLE_GET_PARTY_LEVEL
PyObject* playerGetPartyMemberLevel(PyObject* poSelf, PyObject* poArgs)
{
	int iPID;
	if (!PyTuple_GetInteger(poArgs, 0, &iPID))
		return Py_BuildException();

	CPythonPlayer::TPartyMemberInfo* pPartyMemberInfo;
	if (!CPythonPlayer::Instance().GetPartyMemberPtr(iPID, &pPartyMemberInfo))
		return Py_BuildValue("i", FALSE);

	return Py_BuildValue("i", pPartyMemberInfo->dwLevel);
}
#endif


#ifdef ENABLE_GET_PARTY_LEVEL
		{ "GetPartyMemberLevel",		playerGetPartyMemberLevel,			METH_VARARGS },
#endif