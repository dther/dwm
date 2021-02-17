# dwm - Dther's window manager

My personal fork of suckless'
[dwm, dynamic window manager](https://dwm.suckless.org).

## Features

 * Siji tag icons
 * tmux scratchpad (Super+\`)
 * Extra bar
 * Window swallowing
 * Xrdb integration

## Planned features

 * Advanced workspace management
    - Workspaces that work in tandem and in addition to tags, rather than
      replacing them.
    - A workspace will consist of a set of windows, their tags, the current
      layout and the set of selected tags.
    - Workspaces should be viewable in the bottom right on the extra bar.
 * Fuzzy window finding
    - A fuzzy-matching dmenu prompt with a list of all windows and workspaces.
      The selected window/workspace is switched to.
    - If the window isn't in the selected workspace, switch to that workspace.
    - Otherwise, focus window.
