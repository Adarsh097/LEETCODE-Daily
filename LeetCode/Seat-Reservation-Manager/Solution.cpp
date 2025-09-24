class SeatManager:
    def __init__(self, n: int):
        self.seats =[1]
        
    def reserve(self) -> int:
        reserved_seat = heapq.heappop(self.seats)
        if not self.seats:
            self.seats.append(reserved_seat+1)
        return reserved_seat

    def unreserve(self, seatNumber: int) -> None:
       heapq.heappush(self.seats, seatNumber)