#!/bin/env expect

spawn ghci
expect "*> "
send ":l main.hs\n"
expect "*Main>"
set POINTS 0
set FAIL ""
set TEMP ""

set TEMP $FAIL
set FAIL "$FAIL rankP \[LDI 3, DUP, ADD, LDI 5, SWAP\] 0\n"

send "rankP \[LDI 3, DUP, ADD, LDI 5, SWAP\] 0\n"
expect {
    -ex {Just 2} {
        set POINTS [expr $POINTS+2]
        set FAIL $TEMP
        exp_continue
    }
    *Main>
}

set TEMP $FAIL
set FAIL "$FAIL rankP \[LDI 8, POP 1, LDI 3, DUP, POP 2, LDI 4\] 0\n"

send "rankP \[LDI 8, POP 1, LDI 3, DUP, POP 2, LDI 4\] 0\n"
expect {
    -ex {Just 1} {
        set POINTS [expr $POINTS+2]
        set FAIL $TEMP
        exp_continue
    }
    *Main>
}

set TEMP $FAIL
set FAIL "$FAIL rankP \[LDI 3, LDI 4, LDI 5, MULT, ADD\] 0\n"

send "rankP \[LDI 3, LDI 4, LDI 5, MULT, ADD\] 0\n"
expect {
    -ex {Just 1} {
        set POINTS [expr $POINTS+2]
        set FAIL $TEMP
        exp_continue
    }
    *Main>
}

set TEMP $FAIL
set FAIL "$FAIL rankP \[LDI 2, ADD\] 0\n"

send "rankP \[LDI 2, ADD\] 0\n"
expect {
    -ex {Nothing} {
        set POINTS [expr $POINTS+2]
        set FAIL $TEMP
        exp_continue
    }
    *Main>
}

set TEMP $FAIL
set FAIL "$FAIL rankP \[DUP\] 0\n"

send "rankP \[DUP\] 0\n"
expect {
    -ex {Nothing} {
        set POINTS [expr $POINTS+2]
        set FAIL $TEMP
        exp_continue
    }
    *Main>
}

set TEMP $FAIL
set FAIL "$FAIL rankP \[POP 4\] 0\n"

send "rankP \[POP 4\] 0\n"
expect {
    -ex {Nothing} {
        set POINTS [expr $POINTS+2]
        set FAIL $TEMP
        exp_continue
    }
    *Main>
}

set TEMP $FAIL
set FAIL "$FAIL rankP \[LDB True, IFELSE \[ADD] \[LDI 7\], ADD\] 0\n"

send "rankP \[LDB True, IFELSE \[ADD\] \[LDI 7\], ADD\] 0\n"
expect {
    -ex {Nothing} {
        set POINTS [expr $POINTS+2]
        set FAIL $TEMP
        exp_continue
    }
    *Main>
}

set TEMP $FAIL
set FAIL "$FAIL rankP \[LDB True, LDI 1, LDI 10, LDI 5, IFELSE \[ADD\] \[LDI 7\], ADD\] 0\n"

send "rankP \[LDB True, LDI 1, LDI 10, LDI 5, IFELSE \[ADD\] \[LDI 7\], ADD\] 0\n"
expect {
    -ex {Just 1} {
        set POINTS [expr $POINTS+2]
        set FAIL $TEMP
        exp_continue
    }
    *Main>
}

set TEMP $FAIL
set FAIL "$FAIL rankP \[LDI 20, LDI 1, LDI 10, LDI 5, LEQ, IFELSE \[ADD] \[LDI 7\], DUP\] 0\n"

send "rankP \[LDI 20, LDI 1, LDI 10, LDI 5, LEQ, IFELSE \[ADD] \[LDI 7\], DUP\] 0\n"
expect {
    -ex {Just 2} {
        set POINTS [expr $POINTS+2]
        set FAIL $TEMP
        exp_continue
    }
    *Main>
}

set TEMP $FAIL
set FAIL "$FAIL rankP \[LDB True, LDB False, MULT\] 0\n"

send "rankP \[LDB True, LDB False, MULT\] 0\n"
expect {
    -ex {Just 1} {
        set POINTS [expr $POINTS+2]
        set FAIL $TEMP
        exp_continue
    }
    *Main>
}


set TEMP $FAIL
set FAIL "$FAIL rankP \[LDI 10, DEC, DUP, DUP, DUP, POP 2\] 0\n"

send "rankP \[LDI 10, DEC, DUP, DUP, DUP, POP 2\] 0\n"
expect {
    -ex {Just 2} {
        set POINTS [expr $POINTS+2]
        set FAIL $TEMP
        exp_continue
    }
    *Main>
}

set TEMP $FAIL
set FAIL "$FAIL rankP \[LDI 10, LDI 20, LEQ, DEC\] 0\n"

send "rankP \[LDI 10, LDI 20, LEQ, DEC\] 0\n"
expect {
    -ex {Just 1} {
        set POINTS [expr $POINTS+2]
        set FAIL $TEMP
        exp_continue
    }
    *Main>
}

set TEMP $FAIL
set FAIL "$FAIL rankP \[LDI 10, LDI 5, LDB True, IFELSE \[LDB True, IFELSE \[ADD, DUP\] \[MULT\]\] \[LDI 7\]\] 0\n"

send "rankP \[LDI 10, LDI 5, LDB True, IFELSE \[LDB True, IFELSE \[ADD, DUP\] \[MULT\]\] \[LDI 7\]\] 0\n"
expect {
    -ex {Just 1} {
        set POINTS [expr $POINTS+2]
        set FAIL $TEMP
        exp_continue
    }
    *Main>
}

set TEMP $FAIL
set FAIL "$FAIL rankP \[LDI 10, LDI 5, LDB True, IFELSE \[LDB False, IFELSE \[ADD, DUP\] \[MULT\]\] \[LDI 7\]\] 0\n"

send "rankP \[LDI 10, LDI 5, LDB True, IFELSE \[LDB False, IFELSE \[ADD, DUP\] \[MULT\]\] \[LDI 7\]\] 0\n"
expect {
    -ex {Just 1} {
        set POINTS [expr $POINTS+2]
        set FAIL $TEMP
        exp_continue
    }
    *Main>
}

set TEMP $FAIL
set FAIL "$FAIL rankP \[LDI 10, LDI 5, LDB False, IFELSE \[LDB True, IFELSE \[ADD, DUP\] \[MULT\]\] \[LDI 7\]\] 0\n"

send "rankP \[LDI 10, LDI 5, LDB False, IFELSE \[LDB True, IFELSE \[ADD, DUP\] \[MULT\]\] \[LDI 7\]\] 0\n"
expect {
    -ex {Just 1} {
        set POINTS [expr $POINTS+2]
        set FAIL $TEMP
        exp_continue
    }
    *Main>
}

set TEMP $FAIL
set FAIL "$FAIL rankP \[LDI 10, LDI 5, LDB False, IFELSE \[LDB True, IFELSE \[ADD, ADD\] \[MULT\]\] \[LDI 7\]\] 0\n"

send "rankP \[LDI 10, LDI 5, LDB False, IFELSE \[LDB True, IFELSE \[ADD, ADD\] \[MULT\]\] \[LDI 7\]\] 0\n"
expect {
    -ex {Nothing} {
        set POINTS [expr $POINTS+2]
        set FAIL $TEMP
        exp_continue
    }
    *Main>
}


# ---- run with stacks

set TEMP $FAIL
set FAIL "$FAIL run \[LDI 3, DUP, ADD, LDI 5, SWAP\] \[1\]\n"

send "run \[LDI 3, DUP, ADD, LDI 5, SWAP\] \[1\]\n"
expect {
    -ex {6,5,1} {
        set POINTS [expr $POINTS+2]
        set FAIL $TEMP
        exp_continue
    }
    *Main>
}

set TEMP $FAIL
set FAIL "$FAIL run \[LDI 8, POP 1, LDI 3, DUP, POP 2, LDI 4\] \[2\]\n"

send "run \[LDI 8, POP 1, LDI 3, DUP, POP 2, LDI 4\] \[2\]\n"
expect {
    -ex {4,2} {
        set POINTS [expr $POINTS+2]
        set FAIL $TEMP
        exp_continue
    }
    *Main>
}

set TEMP $FAIL
set FAIL "$FAIL run \[LDI 3, LDI 4, LDI 5, MULT, ADD\] \[1,3\]\n"

send "run \[LDI 3, LDI 4, LDI 5, MULT, ADD\] \[1,3\]\n"
expect {
    -ex {23,1,3} {
        set POINTS [expr $POINTS+2]
        set FAIL $TEMP
        exp_continue
    }
    *Main>
}

set TEMP $FAIL
set FAIL "$FAIL run \[LDI 2, ADD\] \[4\]\n"

send "run \[LDI 2, ADD\] \[4\]\n"
expect {
    -ex {6} {
        set POINTS [expr $POINTS+2]
        set FAIL $TEMP
        exp_continue
    }
    *Main>
}

set TEMP $FAIL
set FAIL "$FAIL run \[DUP\] \[2,4,7\]\n"

send "run \[DUP\] \[2,4,7\]\n"
expect {
    -ex {2,2,4,7} {
        set POINTS [expr $POINTS+2]
        set FAIL $TEMP
        exp_continue
    }
    *Main>
}

set TEMP $FAIL
set FAIL "$FAIL run \[POP 4\] \[1,4,6\]\n"

send "run \[POP 4\] \[1,4,6\]\n"
expect {
    -ex {RankError} {
        set POINTS [expr $POINTS+2]
        set FAIL $TEMP
        exp_continue
    }
    *Main>
}

set TEMP $FAIL
set FAIL "$FAIL run \[LDB True, IFELSE \[ADD] \[LDI 7\], ADD\] \[10\]\n"

send "run \[LDB True, IFELSE \[ADD] \[LDI 7\], ADD\] \[10\]\n"
expect {
    -ex {RankError} {
        set POINTS [expr $POINTS+2]
        set FAIL $TEMP
        exp_continue
    }
    *Main>
}

set TEMP $FAIL
set FAIL "$FAIL run \[LDB True, LDI 1, LDI 10, LDI 5, IFELSE \[ADD\] \[LDI 7\], ADD\] \[100,6\]\n"

send "run \[LDB True, LDI 1, LDI 10, LDI 5, IFELSE \[ADD\] \[LDI 7\], ADD\] \[100,6\]\n"
expect {
    -ex {TypeError} {
        set POINTS [expr $POINTS+2]
        set FAIL $TEMP
        exp_continue
    }
    *Main>
}

set TEMP $FAIL
set FAIL "$FAIL run \[LDI 20, LDI 1, LDI 10, LDI 5, LEQ, IFELSE \[ADD] \[LDI 7\], DUP\] \[10,20,1\]\n"

send "run \[LDI 20, LDI 1, LDI 10, LDI 5, LEQ, IFELSE \[ADD] \[LDI 7\], DUP\] \[10,20,1\]\n"
expect {
    -ex {21,21,10,20,1} {
        set POINTS [expr $POINTS+2]
        set FAIL $TEMP
        exp_continue
    }
    *Main>
}

set TEMP $FAIL
set FAIL "$FAIL run \[LDB True, LDB False, MULT\] \[3,8\]\n"

send "run \[LDB True, LDB True, MULT\] \[3,8\]\n"
expect {
    -ex {TypeError} {
        set POINTS [expr $POINTS+2]
        set FAIL $TEMP
        exp_continue
    }
    *Main>
}


set TEMP $FAIL
set FAIL "$FAIL run \[LDI 10, DEC, DUP, DUP, DUP, POP 2\] \[1,4,6\]\n"

send "run \[LDI 10, DEC, DUP, DUP, DUP, POP 2\] \[1,4,6\]\n"
expect {
    -ex {9,9,1,4,6} {
        set POINTS [expr $POINTS+2]
        set FAIL $TEMP
        exp_continue
    }
    *Main>
}

set TEMP $FAIL
set FAIL "$FAIL run \[LDI 10, LDI 20, LEQ, DEC\] \[10\]\n"

send "run \[LDI 10, LDI 20, LEQ, DEC\] \[10\]\n"
expect {
    -ex {TypeError} {
        set POINTS [expr $POINTS+2]
        set FAIL $TEMP
        exp_continue
    }
    *Main>
}

set TEMP $FAIL
set FAIL "$FAIL run \[LDI 10, LDI 5, LDB True, IFELSE \[LDB True, IFELSE \[ADD, DUP\] \[MULT\]\] \[LDI 7\]\] \[100,6\]\n"

send "run \[LDI 10, LDI 5, LDB True, IFELSE \[LDB True, IFELSE \[ADD, DUP\] \[MULT\]\] \[LDI 7\]\] \[100,6\]\n"
expect {
    -ex {15,15,100,6} {
        set POINTS [expr $POINTS+2]
        set FAIL $TEMP
        exp_continue
    }
    *Main>
}

set TEMP $FAIL
set FAIL "$FAIL run \[LDI 10, LDI 5, LDB True, IFELSE \[LDB False, IFELSE \[ADD, DUP\] \[MULT\]\] \[LDI 7\]\] \[10,20,1\]\n"

send "run \[LDI 10, LDI 5, LDB True, IFELSE \[LDB False, IFELSE \[ADD, DUP\] \[MULT\]\] \[LDI 7\]\] \[10,20,1\]\n"
expect {
    -ex {50,10,20,1} {
        set POINTS [expr $POINTS+2]
        set FAIL $TEMP
        exp_continue
    }
    *Main>
}

set TEMP $FAIL
set FAIL "$FAIL run \[LDI 10, LDI 5, LDB False, IFELSE \[LDB True, IFELSE \[ADD, DUP\] \[MULT\]\] \[LDI 7\]\] \[3,8\]\n"

send "run \[LDI 10, LDI 5, LDB False, IFELSE \[LDB True, IFELSE \[ADD, DUP\] \[MULT\]\] \[LDI 7\]\] \[3,8\]\n"
expect {
    -ex {7,5,10,3,8} {
        set POINTS [expr $POINTS+2]
        set FAIL $TEMP
        exp_continue
    }
    *Main>
}

set TEMP $FAIL
set FAIL "$FAIL run \[LDI 10, LDI 5, LDB False, IFELSE \[LDB True, IFELSE \[ADD, ADD\] \[MULT\]\] \[LDI 7\]\] \[3,8\]\n"

send "run \[LDI 10, LDI 5, LDB False, IFELSE \[LDB True, IFELSE \[ADD, ADD\] \[MULT\]\] \[LDI 7\]\] \[3,8\]\n"
expect {
    -ex {7,5,10,3,8} {
        set POINTS [expr $POINTS+2]
        set FAIL $TEMP
        exp_continue
    }
    *Main>
}

# -- empty stacks


set TEMP $FAIL
set FAIL "$FAIL run \[LDI 3, DUP, ADD, LDI 5, SWAP\] \[\]\n"

send "run \[LDI 3, DUP, ADD, LDI 5, SWAP\] \[\]\n"
expect {
    -ex {6,5} {
        set POINTS [expr $POINTS+2]
        set FAIL $TEMP
        exp_continue
    }
    *Main>
}

set TEMP $FAIL
set FAIL "$FAIL run \[LDI 8, POP 1, LDI 3, DUP, POP 2, LDI 4\] \[\]\n"

send "run \[LDI 8, POP 1, LDI 3, DUP, POP 2, LDI 4\] \[\]\n"
expect {
    -ex {4} {
        set POINTS [expr $POINTS+2]
        set FAIL $TEMP
        exp_continue
    }
    *Main>
}

set TEMP $FAIL
set FAIL "$FAIL run \[LDI 3, LDI 4, LDI 5, MULT, ADD\] \[\]\n"

send "run \[LDI 3, LDI 4, LDI 5, MULT, ADD\] \[\]\n"
expect {
    -ex {23} {
        set POINTS [expr $POINTS+2]
        set FAIL $TEMP
        exp_continue
    }
    *Main>
}

set TEMP $FAIL
set FAIL "$FAIL run \[LDI 2, ADD\] \[\]\n"

send "run \[LDI 2, ADD\] \[\]\n"
expect {
    -ex {RankError} {
        set POINTS [expr $POINTS+2]
        set FAIL $TEMP
        exp_continue
    }
    *Main>
}

set TEMP $FAIL
set FAIL "$FAIL run \[DUP\] \[\]\n"

send "run \[DUP\] \[\]\n"
expect {
    -ex {RankError} {
        set POINTS [expr $POINTS+2]
        set FAIL $TEMP
        exp_continue
    }
    *Main>
}

set TEMP $FAIL
set FAIL "$FAIL run \[POP 4\] \[\]\n"

send "run \[POP 4\] \[\]\n"
expect {
    -ex {RankError} {
        set POINTS [expr $POINTS+2]
        set FAIL $TEMP
        exp_continue
    }
    *Main>
}

set TEMP $FAIL
set FAIL "$FAIL run \[LDB True, IFELSE \[ADD] \[LDI 7\], ADD\] \[\]\n"

send "run \[LDB True, IFELSE \[ADD] \[LDI 7\], ADD\] \[\]\n"
expect {
    -ex {RankError} {
        set POINTS [expr $POINTS+2]
        set FAIL $TEMP
        exp_continue
    }
    *Main>
}

set TEMP $FAIL
set FAIL "$FAIL run \[LDB True, LDI 1, LDI 10, LDI 5, IFELSE \[ADD\] \[LDI 7\], ADD\] \[\]\n"

send "run \[LDB True, LDI 1, LDI 10, LDI 5, IFELSE \[ADD\] \[LDI 7\], ADD\] \[\]\n"
expect {
    -ex {TypeError} {
        set POINTS [expr $POINTS+2]
        set FAIL $TEMP
        exp_continue
    }
    *Main>
}

set TEMP $FAIL
set FAIL "$FAIL run \[LDI 20, LDI 1, LDI 10, LDI 5, LEQ, IFELSE \[ADD] \[LDI 7\], DUP\] \[\]\n"

send "run \[LDI 20, LDI 1, LDI 10, LDI 5, LEQ, IFELSE \[ADD] \[LDI 7\], DUP\] \[\]\n"
expect {
    -ex {21,21} {
        set POINTS [expr $POINTS+2]
        set FAIL $TEMP
        exp_continue
    }
    *Main>
}

set TEMP $FAIL
set FAIL "$FAIL run \[LDB True, LDB False, MULT\] \[\]\n"

send "run \[LDB True, LDB True, MULT\] \[\]\n"
expect {
    -ex {TypeError} {
        set POINTS [expr $POINTS+2]
        set FAIL $TEMP
        exp_continue
    }
    *Main>
}


set TEMP $FAIL
set FAIL "$FAIL run \[LDI 10, DEC, DUP, DUP, DUP, POP 2\] \[\]\n"

send "run \[LDI 10, DEC, DUP, DUP, DUP, POP 2\] \[\]\n"
expect {
    -ex {9,9} {
        set POINTS [expr $POINTS+2]
        set FAIL $TEMP
        exp_continue
    }
    *Main>
}

set TEMP $FAIL
set FAIL "$FAIL run \[LDI 10, LDI 20, LEQ, DEC\] \[\]\n"

send "run \[LDI 10, LDI 20, LEQ, DEC\] \[\]\n"
expect {
    -ex {TypeError} {
        set POINTS [expr $POINTS+2]
        set FAIL $TEMP
        exp_continue
    }
    *Main>
}

set TEMP $FAIL
set FAIL "$FAIL run \[LDI 10, LDI 5, LDB True, IFELSE \[LDB True, IFELSE \[ADD, DUP\] \[MULT\]\] \[LDI 7\]\] \[\]\n"

send "run \[LDI 10, LDI 5, LDB True, IFELSE \[LDB True, IFELSE \[ADD, DUP\] \[MULT\]\] \[LDI 7\]\] \[\]\n"
expect {
    -ex {15,15} {
        set POINTS [expr $POINTS+2]
        set FAIL $TEMP
        exp_continue
    }
    *Main>
}

set TEMP $FAIL
set FAIL "$FAIL run \[LDI 10, LDI 5, LDB True, IFELSE \[LDB False, IFELSE \[ADD, DUP\] \[MULT\]\] \[LDI 7\]\] \[\]\n"

send "run \[LDI 10, LDI 5, LDB True, IFELSE \[LDB False, IFELSE \[ADD, DUP\] \[MULT\]\] \[LDI 7\]\] \[\]\n"
expect {
    -ex {50} {
        set POINTS [expr $POINTS+2]
        set FAIL $TEMP
        exp_continue
    }
    *Main>
}

set TEMP $FAIL
set FAIL "$FAIL run \[LDI 10, LDI 5, LDB False, IFELSE \[LDB True, IFELSE \[ADD, DUP\] \[MULT\]\] \[LDI 7\]\] \[\]\n"

send "run \[LDI 10, LDI 5, LDB False, IFELSE \[LDB True, IFELSE \[ADD, DUP\] \[MULT\]\] \[LDI 7\]\] \[\]\n"
expect {
    -ex {7,5,10} {
        set POINTS [expr $POINTS+2]
        set FAIL $TEMP
        exp_continue
    }
    *Main>
}

set TEMP $FAIL
set FAIL "$FAIL run \[LDI 10, LDI 5, LDB False, IFELSE \[LDB True, IFELSE \[ADD, ADD\] \[MULT\]\] \[LDI 7\]\] \[\]\n"

send "run \[LDI 10, LDI 5, LDB False, IFELSE \[LDB True, IFELSE \[ADD, ADD\] \[MULT\]\] \[LDI 7\]\] \[\]\n"
expect {
    -ex {RankError} {
        set POINTS [expr $POINTS+2]
        set FAIL $TEMP
        exp_continue
    }
    *Main>
}

set POINTS [expr $POINTS-2]
# ---------------------------Do not modify-------------------------------
send ":quit"

# Clear output
puts \033\[2J


# -- Formatting for output and recollecting the color scheme of terminal
puts "\033\[00;33m"
puts "\033\[01;34m"
puts "-----------------------------------------------"
puts "\033\[01;31m"
puts "Failed functions"
puts "\033\[01;34m"
puts "$FAIL"
puts "-----------------------------------------------"
puts "\033\[01;32m"

puts "\033\[00;0m"

