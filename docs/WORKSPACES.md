# Workspaces

This is an outline for what I need to implement to make workspaces work
the way I want them to.

## Done

 - Workspace struct
 - Monitor workspace state
 - Array of workspaces
 - `setws(int ws)` -
   Saves the current monitor settings to the current workspace,
   Sets the selected monitor's settings to reflect
   the new workspace's settings.
 - `workspace(const Arg* arg)` -
   Switches to specific workspace.
 - Client workspace ownership + Hiding
 - Tags only show window presence in the active workspace
 - Workspace bar, like the tag bar
 - Clickable workspace bar
 - Some way of moving windows from workspaces

## Planned

 - Keyboard method of switching and moving windows to workspaces,
   probably utilising dwmfifo or fsignal.
 - Rules for sending clients to workspaces
   (that only apply when not moving them to new ones)
