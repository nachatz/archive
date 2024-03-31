#!/bin/env expect

# Author: Nikolas Achatz
# Course: CS 381 OSU
# Assignment: HW2

set SCORE 2
set TEMP 2
set FAIL ""
set timeout 1

spawn ghci
expect ".*> "
send ":l main.hs\n"
expect "*Main>"

send "norm(ins 8 \[(5,1),(6,1),(8,15),(9,1)\])\n"
expect {
        "(5,1),(6,1),(8,16),(9,1)"  
            {set SCORE [expr $SCORE+7]}
}

if { $SCORE > $TEMP } {
    set TEMP [expr $TEMP+7]
} else {
    set FAIL " Insert - should match (5,1),(6,1),(8,16),(9,1)\n"
}


send "norm(del 6 \[(5,1),(6,1),(8,15),(9,1)\])\n"
expect {
        "(5,1),(8,15),(9,1)"  
            {set SCORE [expr $SCORE+7]}
}

if { $SCORE > $TEMP } {
    set TEMP [expr $TEMP+7]
} else {
    set FAIL "$FAIL Delete - should match (5,1),(8,15),(9,1)\n"
}

send "norm(bag \[5,5,5,6,6,7,7,7,8\])\n"
expect {
        "(5,3),(6,2),(7,3),(8,1)"  
            {set SCORE [expr $SCORE+7]}
}

if { $SCORE > $TEMP } {
    set TEMP [expr $TEMP+7]
} else {
    set FAIL "$FAIL Bag - should match (5,3),(6,2),(7,3),(8,1)\n"
}

send "subbag \[(8,1),(7,3)\] \[(8,1),(7,3),(6,2),(5,3)\]\n"
expect {
        "True"  
            {set SCORE [expr $SCORE+7]}
}

if { $SCORE > $TEMP } {
    set TEMP [expr $TEMP+7]
} else {
    set FAIL "$FAIL Subbag - should match True\n"
}

send "isSet \[(8,1),(7,3),(6,2),(5,3)\]\n"
expect {
        "False"  
            {set SCORE [expr $SCORE+7]}
}

if { $SCORE > $TEMP } {
    set TEMP [expr $TEMP+7]
} else {
    set FAIL "$FAIL IsSet - should match False\n"
}

send "size \[(8,1),(7,3),(6,2),(5,3)\]\n"
expect {
        "9"  
            {set SCORE [expr $SCORE+7]}
}

if { $SCORE > $TEMP } {
    set TEMP [expr $TEMP+7]
} else {
    set FAIL "$FAIL Size - should match 9\n"
}

send "norm(nodes \[(1,2),(1,3),(2,3),(2,4),(3,4)\])\n"
expect {
        "1,2,3,4"  
            {set SCORE [expr $SCORE+7]}
}

if { $SCORE > $TEMP } {
    set TEMP [expr $TEMP+7]
} else {
    set FAIL "$FAIL Nodes - should match \[1,2,3,4\]\n"
}

send "norm(suc 2 \[(1,2),(1,3),(2,3),(2,4),(3,4)\])\n"
expect {
        "3,4"  
            {set SCORE [expr $SCORE+7]}
}

if { $SCORE > $TEMP } {
    set TEMP [expr $TEMP+7]
} else {
    set FAIL "$FAIL Suc - should match \[3,4\]\n"
}

send "norm(detach 3 \[(1,2),(1,3),(2,3),(2,4),(3,4)\])\n"
expect {
        "(1,2),(2,4)"  
            {set SCORE [expr $SCORE+7]}
}

if { $SCORE > $TEMP } {
    set TEMP [expr $TEMP+7]
} else {
    set FAIL "$FAIL Detach - should match \[(1,2),(2,4)\]\n"
}

send "norm(cyc 4)\n"
expect {
        "(1,2),(2,3),(3,4),(4,1)"  
            {set SCORE [expr $SCORE+7]}
}

if { $SCORE > $TEMP } {
    set TEMP [expr $TEMP+7]
} else {
    set FAIL "$FAIL Cyc - should match \[(1,2),(2,3),(3,4),(4,1)\]\n"
}

send "map width \[Pt (4,4), Circle (5,5) 3, Rect (3,3) 7 2\]\n"
expect {
        "0,6,7"  
            {set SCORE [expr $SCORE+7]}
}

if { $SCORE > $TEMP } {
    set TEMP [expr $TEMP+7]
} else {
    set FAIL "$FAIL Width - should match \[0,6,7\]\n"
}

send "map bbox \[Pt (4,4), Circle (5,5) 3, Rect (3,3) 7 2\]\n"
expect {
        "((4,4),(4,4)),((2,2),(8,8)),((3,3),(10,5))"  
            {set SCORE [expr $SCORE+7]}
}

if { $SCORE > $TEMP } {
    set TEMP [expr $TEMP+7]
} else {
    set FAIL "$FAIL Width - should match \[((4,4),(4,4)),((2,2),(8,8)),((3,3),(10,5))\]\n"
}

send "map minX \[Pt (4,4), Circle (5,5) 3, Rect (3,3) 7 2\]\n"
expect {
        "4,2,3"  
            {set SCORE [expr $SCORE+7]}
}

if { $SCORE > $TEMP } {
    set TEMP [expr $TEMP+7]
} else {
    set FAIL "$FAIL MinX - should match \[4,2,3\]\n"
}

send "move (Rect (4,4) 5 9) (5,5)\n"
expect {
        "(9,9)"  
            {set SCORE [expr $SCORE+7]}
}

if { $SCORE > $TEMP } {
    set TEMP [expr $TEMP+7]
} else {
    set FAIL "$FAIL Move - should match (9,9) Rect\n"
}


send ":quit"
puts \033\[2J


puts "\033\[00;33m"
puts "Predicted Grade"
puts "\033\[01;34m"
puts "-----------------------------------------------"
puts "\033\[01;31m"
puts "Failed functions"
puts "$FAIL"
puts "\033\[01;34m"
puts "-----------------------------------------------"
puts "\033\[01;32m"
puts "$SCORE/100\r"
puts "\033\[00;0m"



