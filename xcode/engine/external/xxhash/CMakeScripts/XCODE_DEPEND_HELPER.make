# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.ext_xxhash.Debug:
/Users/arlex/Documents/Project/MyGame/xcode/lib/Debug/libext_xxhash.a:
	/bin/rm -f /Users/arlex/Documents/Project/MyGame/xcode/lib/Debug/libext_xxhash.a


PostBuild.ext_xxhash.Release:
/Users/arlex/Documents/Project/MyGame/xcode/lib/Release/libext_xxhash.a:
	/bin/rm -f /Users/arlex/Documents/Project/MyGame/xcode/lib/Release/libext_xxhash.a


PostBuild.ext_xxhash.MinSizeRel:
/Users/arlex/Documents/Project/MyGame/xcode/lib/MinSizeRel/libext_xxhash.a:
	/bin/rm -f /Users/arlex/Documents/Project/MyGame/xcode/lib/MinSizeRel/libext_xxhash.a


PostBuild.ext_xxhash.RelWithDebInfo:
/Users/arlex/Documents/Project/MyGame/xcode/lib/RelWithDebInfo/libext_xxhash.a:
	/bin/rm -f /Users/arlex/Documents/Project/MyGame/xcode/lib/RelWithDebInfo/libext_xxhash.a




# For each target create a dummy ruleso the target does not have to exist
