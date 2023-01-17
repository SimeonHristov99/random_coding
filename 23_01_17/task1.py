# Better approach
# def number(stops):
#     return sum(i - o for i, o in stops)

def number(bus_stops):
    result = 0
    for on, off in bus_stops:
        result = result + on - off
    return result
