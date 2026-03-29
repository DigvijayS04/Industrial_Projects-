class Node:
    def __init__(self,value):
        self.data = value
        self.next = None
        self.prev = None

class DoublyLLL:
    def __init__(self):
        self.first = None
        self.iCount = 0

    def InsertFirst(self, no):
        newn = Node(no)

        if(self.first == None):
            self.first = newn

        else:
            newn.next = self.first
            self.first.prev = newn
            self.first = newn


        self.iCount = self.iCount + 1

    def InsertLast(self,no):
        newn = Node(no)

        if(self.first == None):
            self.first = newn

        else:
            temp = self.first

            while(temp.next != None):
                temp = temp.next

            temp.next = newn
            newn.prev = temp

        self.iCount = self.iCount + 1

    def InsertAtPos(self, no, pos):
        
        if(pos < 1 or pos > (self.iCount + 1)):
            print("Invalid position")
            return
        
        if(pos == 1):
            self.InsertFirst(no)
            return
        
        elif(pos == (self.iCount + 1)):
            self.InsertLast(no)
            return

        else:
            newn = Node(no)
            temp = self.first

            for i in range(1,pos-1):
                temp = temp.next
            
            newn.next = temp.next
            temp.next.prev = newn
            
            temp.next = newn
            newn.prev = temp

            self.iCount = self.iCount + 1               


    def DeleteFirst(self):
        if(self.first == None and self.last == None):
            return

        if(self.first.next == None):
            del self.first 
            self.first = None

        else:
            self.first = self.first.next
            del self.first.prev
            self.first.prev = None

        self.iCount = self.iCount - 1
        

    def DeleteLast(self):
        if(self.first == None):
            return

        if(self.first.next == None):
            del self.first 
            self.first = None

        else:
            temp = self.first

            while(temp.next.next != None):
                temp = temp.next

            del temp.next
            temp.next = None           

        self.iCount = self.iCount - 1

    def DeleteAtPos(self, pos):
        if(pos < 1 or pos > self.iCount):
            print("Invalid position")
            return
        
        if(pos == 1):
            self.DeleteFirst(no)
            return
        
        elif(pos == self.iCount):
            self.DeleteLast(no)
            return

        else:
            temp = self.first

            for i in range(1,pos-1):
                temp = temp.next

            temp.next = temp.next.next
            temp.next.prev = temp
        
            self.iCount = self.iCount - 1


    def Display(self):
        temp = self.first

        while(temp != None):
            print("|",temp.data,"|->",end = " ")
            temp = temp.next

        print("None")

    def Count(self):
        return self.iCount

def main():
    dobj = DoublyLLL()

    dobj.InsertFirst(51)
    dobj.InsertFirst(21)
    dobj.InsertFirst(11)

    print("Elements of List are: ")
    dobj.Display()

    print("Number of elements in linkedlist are : ",dobj.Count())

    dobj.InsertLast(101)
    dobj.InsertLast(111)
    print("Elements of List are: ")
    dobj.Display()

    print("Number of elements in linkedlist are : ",dobj.Count())

    dobj.InsertAtPos(71,4)
    print("Elements of List are: ")
    dobj.Display()

    print("Number of elements in linkedlist are : ",dobj.Count())

    dobj.DeleteFirst()
    print("Elements of List are: ")
    dobj.Display()

    print("Number of elements in linkedlist are : ",dobj.Count())

    dobj.DeleteLast()
    print("Elements of List are: ")
    dobj.Display()

    print("Number of elements in linkedlist are : ",dobj.Count())

    dobj.DeleteAtPos(3)
    print("Elements of List are: ")
    dobj.Display()

    print("Number of elements in linkedlist are : ",dobj.Count())
    
    
if __name__ == "__main__":
    main()
