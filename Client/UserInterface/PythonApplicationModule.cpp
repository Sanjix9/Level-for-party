#ifdef ENABLE_GET_PARTY_LEVEL
	PyModule_AddIntConstant(poModule, "ENABLE_GET_PARTY_LEVEL", 1);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_GET_PARTY_LEVEL", 0);
#endif