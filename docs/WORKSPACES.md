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

## Planned

 - Workspace bar, like the tag bar
 - Tags only show window presence in the active workspace
 - Some way of moving windows from workspaces...
   Haven't figured it out yet.
