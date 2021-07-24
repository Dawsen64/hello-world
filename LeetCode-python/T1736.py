class Solution:
    def maximumTime(self, time: str) -> str:
        newtime = ""
        if time[0] == "?" and time[1] < "4":
            newtime += "2"
        elif time[0] == "?" and time[1] >= "4" and time[1] <= "9":
            newtime += "1"
        elif time[0] == "?" and time[1] == "?":
            newtime += "2"
        else: newtime += time[0]

        if time[1] == "?":
            if time[0] <= "1":
                newtime += "9"
            else: newtime += "3"
        else: newtime += time[1]

        newtime += ":"
        
        if time[3] == "?":
            newtime += "5"
        else: newtime += time[3]
    
        if time[4] == "?":
            newtime += "9"
        else: newtime += time[4]
        return newtime
