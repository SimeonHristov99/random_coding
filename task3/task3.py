def will_it_return(str):
    pos_x = 0
    pos_y = 0
    
    for i in str:
        if i == 'L':
            pos_x += 1
        elif i == 'R':
            pos_x -= 1
        elif i == 'U':
            pos_y += 2
        elif i == 'D':
            pos_y -= 2
    
    return pos_x == 0 and pos_y == 0


print(will_it_return("LR"))  # True
print(will_it_return("URURD"))  # False
print(will_it_return("RUULLDRD"))  # True