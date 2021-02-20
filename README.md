# dwm - Dther's window manager

My personal fork of suckless'
[dwm, dynamic window manager](https://dwm.suckless.org).

## Features

 * Advanced workspace management, inspired by
 [awm](https://github.com/Alpt/awm)
 * Siji tag icons
 * tmux scratchpad (Super+\`)
 * Extra bar
 * Window swallowing
 * Xrdb integration

## Planned features

 * Fuzzy window finding
    - Using a fuzzy dmenu prompt, select windows and automatically
      switch to them.
    - Needs Extended Window Management Hints, like
   [focusonnetactive](https://dwm.suckless.org/patches/focusonnetactive/) or
   [ewmhtags](https://dwm.suckless.org/patches/ewmhtags/).
 * dmenu workspaces selector
    - something like [dwmfifo](https://dwm.suckless.org/patches/dwmfifo)
      and a shell script is probably best for this.
