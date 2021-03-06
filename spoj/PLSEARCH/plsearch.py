
import sys, math


import math
def trig_dotproduct(a,b):
    return sum([a[i]*b[i] for i in range(len(a))])
     
     
#Calculates the size of a vector
def trig_veclength(a):
    return sum([a[i]**2 for i in range(len(a))])**.5
     
#Calculates the angle between two vector
def trig_angle(a,b):
    dp=trig_dotproduct(a,b)
    la=trig_veclength(a)
    lb=trig_veclength(b)
    costheta=dp/(la*lb)
    return math.acos(costheta)

def trig_angle_alt(x,y):
    angle = math.degrees(math.atan2(x, y))
    if angle<0:
        angle += 360
    #print "x=",x,"y=",y,"angle=",angle
    return math.radians(angle)
    
def searchSameShape(template, linestrings_vector):
    count=1
    ret=[]
    
   
    
    for l in linestrings_vector:
        if template.isTopologicallyEqual(l)==True:
            ret=ret+[count]
        count=count+1
    return ret


class Linestring:
    def __init__(self):
        self.points=[]
    def addPoint(self, x, y):
        self.points.append([x,y])
        
    def reverse(self):
        self.points.reverse()

    def translate(self, disp_x, disp_y):
        for i in range(self.points):
            self.points[i][0]=self.points[i]+disp_x
            self.points[i][1]=self.points[i]+disp_y
    
    def moveToOrigin(self):
        self.translate(self.points[0][0]*-1,self.points[0][0]*-1)
        
          
    def rotate(self, angle):
        pass
        
    def dump(self):
        print self.points        
    
    def saveToDatabase(self, dbname, table, number):
        import pg
        conn=pg.connect("landgen_gis")
        wkt="LINESTRING("+",".join([str(p[0])+" "+str(p[1]) for p in self.points])+")"
        conn.query("insert into "+table+"(number, the_geom) values('"+number+"','"+wkt+"')")
        #for p in self.points:
            
            
        
    def __isTopologicallyEqualPointsVectors(self, points_self, points_other):
        #print "ORIGINAL------"
        #print "tmplt",points_self
        #print "other",points_other
        #print "----------------"
        #translation to same referential (no scalling!)
        x0_self=points_self[0][0]
        y0_self=points_self[0][1]
        x0_other=points_other[0][0]
        y0_other=points_other[0][1]
        for i in range(len(points_self)):
            points_self[i][0]  = points_self[i][0]-x0_self
            points_self[i][1]  = points_self[i][1]-y0_self
            points_other[i][0] = points_other[i][0]-x0_other
            points_other[i][1] = points_other[i][1]-y0_other

        #rotation by the angle of the first vector
        
        #angle_self=trig_angle([0,1],[points_self[1][0],points_self[1][1]])
        #angle_self=math.atan2(points_self[1][0],points_self[1][1])
        angle_self=trig_angle_alt(points_self[1][0],points_self[1][1])
        #print "angle_self=",angle_self
        for i in range(len(points_self)):
            
            rot_x=points_self[i][0]*math.cos(angle_self)-points_self[i][1]*math.sin(angle_self)
            rot_y=points_self[i][0]*math.sin(angle_self)+points_self[i][1]*math.cos(angle_self)
            
            points_self[i][0]=round(rot_x,8)
            points_self[i][1]=round(rot_y,8)
        
        
        #angle_other=trig_angle([0,1],[points_other[1][0],points_other[1][1]])
        #angle_other=math.atan2(points_other[1][0],points_other[1][1])
        #print "points_other=",points_other
        angle_other=trig_angle_alt(points_other[1][0],points_other[1][1])
        #print "angle_other=",angle_other
        for i in range(len(points_other)):
            rot_x=(points_other[i][0]*math.cos(angle_other))-(points_other[i][1]*math.sin(angle_other))
            rot_y=(points_other[i][0]*math.sin(angle_other))+(points_other[i][1]*math.cos(angle_other))
            
            points_other[i][0]=round(rot_x,8)
            points_other[i][1]=round(rot_y,8)
        
        #print "TRANSFORMED------"
        #print "tmplt",points_self
        #print "other",points_other
        #print "----------------"
        #check equality
        ret=True
        for i in range(len(points_self)):
            if points_self[i][0]!=points_other[i][0] or points_self[i][1]!=points_other[i][1]:
                ret=False
                
        return ret
    #detect topological similarity
    def isTopologicallyEqual(self, other_linestring):
        points_self=[]
        points_self_2=[]
        points_other=[]
        points_other_reversed=[]
        
        #copy the points (changing the state could be destructive)
        for p in self.points:
            points_self.append([p[0],p[1]])
            points_self_2.append([p[0],p[1]])
        for p in other_linestring.points:
            points_other.append([p[0],p[1]])
            points_other_reversed.append([p[0],p[1]])
        points_other_reversed=points_other_reversed[::-1]    
        ret=self.__isTopologicallyEqualPointsVectors(points_self, points_other)
        if ret==False:
            return self.__isTopologicallyEqualPointsVectors(points_self_2, points_other_reversed)
        return ret
        
        
        
        
        
        

if __name__=='__main__':

    #print math.degrees(trig_angle([0,1],[-1,-1])),trig_angle([0,1],[-1,-1]),math.radians(math.degrees(trig_angle([0,1],[-1,-1])))
    #print math.degrees(trig_angle([0,1],[1,1])),trig_angle([0,1],[1,1]),math.radians(math.degrees(trig_angle([0,1],[1,1]))) 
    #print math.degrees(trig_angle([0,1],[-2,0])),trig_angle([0,1],[-2,0]),math.radians(math.degrees(trig_angle([0,1],[-2,0])))
    #
    #sys.exit(0)
    while True:
        nlines=int(raw_input())
        if nlines==0:
            sys.exit(0)
        lines=[]
        for i in range(nlines+1):
        
            npoints=int(raw_input())
            l=Linestring()
            for j in range(npoints):
                tok=raw_input().split(" ")
                l.addPoint(float(tok[0]),float(tok[1]))
            lines.append(l)
        #print "ORIGINAL LINES"
        #count=0
        #for l in lines:
        #    l.dump()
        ##    l.saveToDatabase("landgen_gis",'spoj_linestring',str(count))
        #   count=count+1
        #print "--------------"
        matches=searchSameShape(lines[0],lines[1:])
        for m in matches:
            print m        
        print "+++++"

