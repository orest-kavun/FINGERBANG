%{
    #include "Node.h"
    #include "cry.tab.h"
%}

%%
"💃" { return FORWARD; }
"🏃" { return REWIND; }
"📈" { return INCREMENT; }
"📉" { return DECREMENT; }
"🌜" { return LOOP; }
"🌛" { return IN; }
"👽" { return OUTPUT; }
"🧠" { return MEMDMP;}
. { }
\n { }
