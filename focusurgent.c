static void
focusurgent(const Arg *arg) {
	Client *c;
	for(c=selmon->clients; c && !c->isurgent; c=c->next);
	if(c) {
		if(!ISVISIBLE(c)) {
			const Arg a = {.ui = c->tags};
			setws(c->ws);
			view(&a);
		}
		if(ISVISIBLE(c))
				focus(c);
        restack(selmon);
	}
}
