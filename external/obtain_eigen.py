import obtain
import os
import sys
import shutil
import SCons.Errors as Errors

# Download Eigen3
version   = '3.2.7'
base      = 'Eigen'
name      = 'Eigen v' + version
directory = 'eigen-eigen-b30b87236a1b'
url       = 'https://gitlab.com/libeigen/eigen/-/archive/3.2.7/eigen-' + version + '.tar.gz'
filename  = 'eigen-' + version + '.tar.gz'
sha256    = '3119570be9d245089fd723a27b8751c127f160f045bb2b385b681c27026563f1'
obtained  = obtain.obtain(name, directory, url, filename, sha256)

if obtained:
   rep = 'build' + os.sep + 'include' + os.sep + 'Eigen'
   if not os.path.exists(rep):
      shutil.copytree(directory + os.sep + 'Eigen', rep)

   unsup_rep = 'build' + os.sep + 'include' + os.sep + 'unsupported'
   if not os.path.exists(unsup_rep):
      shutil.copytree(directory + os.sep + 'unsupported', unsup_rep)

else:
   msg = "download from '" + url + "' failed"
   raise Errors.BuildError(errstr = msg,
                           filename = filename,
                           exitstatus = 1)
