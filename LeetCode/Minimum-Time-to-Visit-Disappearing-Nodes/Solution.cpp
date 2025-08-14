def travel(curr, visited, num):
    if num >= disappear[curr]:
        return
    visited.add(curr)
    if time[curr] == -1:
        time[curr] = num
    else:
        time[curr] = min(time[curr], num)

    for next_node, value in graph[curr].items():
        if next_node not in visited:
            travel(next_node, visited, num + value)
    visited.remove(curr)
    return