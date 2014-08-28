#!/home/nerdybuzz/Projects/EsoBox/boxlang

Open Box
    # This is a simple program written in BoxPL.
    pack <What is your first name? > fname
    pack <What is your last name? > lname
    unpack [Hello ]
    unwrap fname
    unpack [ ]
    unwrap lname
    unpack [!]
    makeline
    unpack [Welcome!!]
    makeline
Close Box
