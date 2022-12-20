Figures is a simple package providing a way for creating and manipulation of geometrical ﬁgures.
User can adds its own ﬁgures conforming the "Figure" interface. The manipulation of ﬁgures is
realized in a batch form using the class "Batch". Batch runs commands implementing "Command" interface.
User can add its own command conforming "Command" interface. Batch implements the methods "Execute" and
"Validate" for applying commands and checking if after manipulations ﬁgures don't overlap.
