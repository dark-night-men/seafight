
'''
#comment
'''

import random

class Bearing:
    HR = 0
    VR = 1

    def seq():
        return [Bearing.HR,Bearing.VR]

class ShipClass:
    X1 = 1
    X2 = 2
    X3 = 3
    X4 = 4

    def seq():
        return [ShipClass.X1 ,ShipClass.X2 , ShipClass.X3 ,  ShipClass.X4 ]

# First coord is 0
class Field:
    filedSize = 10

    def __init__( self ):
        self.ships = []
        self.occupied = [ [ 0 for x in xrange( Field.filedSize ) ] for x in xrange( Field.filedSize ) ]

    def isShipSuitable( self , ship ):

        i = 0
        result = True
        while i < ship.shipClass and result :
            if ship.bearing == Bearing.HR:
                if self.occupied[ ship.pos[1] ][ ship.pos[0] + i]
            else:

        return

class Ship:
    def __init__( self , bearing , shipClass , pos ):

        self.bearing = bearing
        self.shipClass = shipClass
        self.pos = pos

    @staticmethod
    def genShip( bearing , shipClass ):
        return Ship( bearing , shipClass , [ random.randrange( -1 , Field.filedSize ) for x in xrange( 2 ) ] )





p4 = Ship( Bearing.HR , 4 , [1,1] )

print dir( p4 )


print "Hello World"
print( p4.bearing , p4.size )


m =  [ 0 for x in xrange(5) ]
