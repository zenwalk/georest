# This file was automatically generated by SWIG (http://www.swig.org).
# Version 1.3.35
#
# Don't modify this file, modify the SWIG interface instead.
# This file is compatible with both classic and new-style classes.

import _kmlengine
import new
new_instancemethod = new.instancemethod
try:
    _swig_property = property
except NameError:
    pass # Python < 2.2 doesn't have 'property'.
def _swig_setattr_nondynamic(self,class_type,name,value,static=1):
    if (name == "thisown"): return self.this.own(value)
    if (name == "this"):
        if type(value).__name__ == 'PySwigObject':
            self.__dict__[name] = value
            return
    method = class_type.__swig_setmethods__.get(name,None)
    if method: return method(self,value)
    if (not static) or hasattr(self,name):
        self.__dict__[name] = value
    else:
        raise AttributeError("You cannot add attributes to %s" % self)

def _swig_setattr(self,class_type,name,value):
    return _swig_setattr_nondynamic(self,class_type,name,value,0)

def _swig_getattr(self,class_type,name):
    if (name == "thisown"): return self.this.own()
    method = class_type.__swig_getmethods__.get(name,None)
    if method: return method(self)
    raise AttributeError,name

def _swig_repr(self):
    try: strthis = "proxy of " + self.this.__repr__()
    except: strthis = ""
    return "<%s.%s; %s >" % (self.__class__.__module__, self.__class__.__name__, strthis,)

import types
try:
    _object = types.ObjectType
    _newclass = 1
except AttributeError:
    class _object : pass
    _newclass = 0
del types


import kmldom
import kmlbase
class Bbox(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Bbox, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Bbox, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        this = _kmlengine.new_Bbox(*args)
        try: self.this.append(this)
        except: self.this = this
    def Contains(*args): return _kmlengine.Bbox_Contains(*args)
    def ExpandFromBbox(*args): return _kmlengine.Bbox_ExpandFromBbox(*args)
    def ExpandLatitude(*args): return _kmlengine.Bbox_ExpandLatitude(*args)
    def ExpandLongitude(*args): return _kmlengine.Bbox_ExpandLongitude(*args)
    def ExpandLatLon(*args): return _kmlengine.Bbox_ExpandLatLon(*args)
    def get_north(*args): return _kmlengine.Bbox_get_north(*args)
    def get_south(*args): return _kmlengine.Bbox_get_south(*args)
    def get_east(*args): return _kmlengine.Bbox_get_east(*args)
    def get_west(*args): return _kmlengine.Bbox_get_west(*args)
    __swig_destroy__ = _kmlengine.delete_Bbox
    __del__ = lambda self : None;
Bbox_swigregister = _kmlengine.Bbox_swigregister
Bbox_swigregister(Bbox)

Clone = _kmlengine.Clone
GetFeatureBounds = _kmlengine.GetFeatureBounds
GetFeatureLatLon = _kmlengine.GetFeatureLatLon
GetRootFeature = _kmlengine.GetRootFeature
class KmlFile(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, KmlFile, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, KmlFile, name)
    def __init__(self, *args, **kwargs): raise AttributeError, "No constructor defined"
    __repr__ = _swig_repr
    __swig_getmethods__["CreateFromParse"] = lambda x: _kmlengine.KmlFile_CreateFromParse
    if _newclass:CreateFromParse = staticmethod(_kmlengine.KmlFile_CreateFromParse)
    __swig_getmethods__["CreateFromImport"] = lambda x: _kmlengine.KmlFile_CreateFromImport
    if _newclass:CreateFromImport = staticmethod(_kmlengine.KmlFile_CreateFromImport)
    def get_root(*args): return _kmlengine.KmlFile_get_root(*args)
    def SerializeToString(*args): return _kmlengine.KmlFile_SerializeToString(*args)
    def GetObjectById(*args): return _kmlengine.KmlFile_GetObjectById(*args)
    def GetSharedStyleById(*args): return _kmlengine.KmlFile_GetSharedStyleById(*args)
    __swig_destroy__ = _kmlengine.delete_KmlFile
    __del__ = lambda self : None;
KmlFile_swigregister = _kmlengine.KmlFile_swigregister
KmlFile_swigregister(KmlFile)
KmlFile_CreateFromParse = _kmlengine.KmlFile_CreateFromParse
KmlFile_CreateFromImport = _kmlengine.KmlFile_CreateFromImport

class KmzFile(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, KmzFile, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, KmzFile, name)
    def __init__(self, *args, **kwargs): raise AttributeError, "No constructor defined"
    __repr__ = _swig_repr
    __swig_getmethods__["OpenFromFile"] = lambda x: _kmlengine.KmzFile_OpenFromFile
    if _newclass:OpenFromFile = staticmethod(_kmlengine.KmzFile_OpenFromFile)
    __swig_getmethods__["CreateFromString"] = lambda x: _kmlengine.KmzFile_CreateFromString
    if _newclass:CreateFromString = staticmethod(_kmlengine.KmzFile_CreateFromString)
    def ReadKml(*args): return _kmlengine.KmzFile_ReadKml(*args)
    def ReadFile(*args): return _kmlengine.KmzFile_ReadFile(*args)
    __swig_destroy__ = _kmlengine.delete_KmzFile
    __del__ = lambda self : None;
KmzFile_swigregister = _kmlengine.KmzFile_swigregister
KmzFile_swigregister(KmzFile)
KmzFile_OpenFromFile = _kmlengine.KmzFile_OpenFromFile
KmzFile_CreateFromString = _kmlengine.KmzFile_CreateFromString

KmzSplit = _kmlengine.KmzSplit
SplitUri = _kmlengine.SplitUri


