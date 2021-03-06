#!/usr/bin/python

import unittest
import pyngl

# Note all pyngl types use internal fuzzy float equality operators

class TestVec2(unittest.TestCase):
  def testdefaultCtor(self):
    test=pyngl.Vec2()
    result=pyngl.Vec2(0.0,0.0)         
    self.assertEqual( test,result)

  def testDotProduct(self) :
    a=pyngl.Vec2(1.0,2.0);
    b=pyngl.Vec2(4.0,5.0);
    self.assertEqual(a.dot(b),14.0);

  def testNull(self) :
    test=pyngl.Vec2(1,2)
    test.null()
    self.assertTrue(test==pyngl.Vec2.zero())

  def testNormalize(self) :
    test=pyngl.Vec2(22.3,0.5)
    test.normalize() 
    result=pyngl.Vec2(0.9997,0.0224)
    self.assertTrue(test==result)  
    self.assertEqual(test,result)


  def testLength(self) :
    a=pyngl.Vec2(22.0,1.0)
    self.assertAlmostEqual(a.length(),22.022,delta=0.001)

  def testLengthSquared(self) :
    a=pyngl.Vec2(22.0,1.0)
    self.assertAlmostEqual(a.lengthSquared(),485.0,delta=0.001)


  def testSubscipt(self) :
    test=pyngl.Vec2(1,2)
    self.assertAlmostEqual(test[0],1.0)
    self.assertAlmostEqual(test[1],2.0)

  def testFloatCtor(self) :
    test=pyngl.Vec2(1.0,2.0)
    result=pyngl.Vec2(1.0,2.0)
    self.assertEqual(test,result)

  def testAssignOperator(self) :
    test=pyngl.Vec2(1.0,2.0)
    copy=test
    result=pyngl.Vec2(1.0,2.0)
    self.assertEqual(test,result)

if __name__ == '__main__':
     unittest.main()
