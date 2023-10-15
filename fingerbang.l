%{
    #include "Node.h"
    #include "fingerbang.tab.h"
%}

%%
"👉" { return FORWARD; }
"👈" { return REWIND; }
"👆" { return INCREMENT; }
"👇" { return DECREMENT; }
"👍" { return LOOP; }
"👎" { return IN; }
"🤮" { return OUTPUT; }
"🧠" { return MEMDMP;}
. { }
\n { }
