static void
focusurgent(const Arg *arg) {
	Client *c;
	Monitor *m;
	/* Prioritise this monitor's urgent clients first */
	for(c=selmon->clients; c && !c->isurgent; c=c->next);
	if(!c) {
		// TODO: test this- should search other monitors for urgent clients
		for(m=mons; m && !c; m=m->next) {
			if (m == selmon) continue; /* Skip current monitor - already checked */
			for(c=m->clients; c && !c->isurgent; c=c->next);
		}
	}

	if (c) {
		selmon = c->mon;
		if(!ISVISIBLE(c)) {
			const Arg a = {.ui = (c->tags | selmon->tagset[selmon->seltags])};
			if(!ISVISIBLE(c)) view(&a);
		}
		if(ISVISIBLE(c))
				focusjump(c);
		restack(selmon);
	}
}
