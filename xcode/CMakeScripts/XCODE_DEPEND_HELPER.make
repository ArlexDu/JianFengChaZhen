# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.MyGame.Debug:
PostBuild.cocos2d.Debug: /Users/arlex/Documents/Project/MyGame/xcode/bin/MyGame/Debug/MyGame.app/Contents/MacOS/MyGame
PostBuild.external.Debug: /Users/arlex/Documents/Project/MyGame/xcode/bin/MyGame/Debug/MyGame.app/Contents/MacOS/MyGame
PostBuild.ext_recast.Debug: /Users/arlex/Documents/Project/MyGame/xcode/bin/MyGame/Debug/MyGame.app/Contents/MacOS/MyGame
PostBuild.ext_tinyxml2.Debug: /Users/arlex/Documents/Project/MyGame/xcode/bin/MyGame/Debug/MyGame.app/Contents/MacOS/MyGame
PostBuild.ext_xxhash.Debug: /Users/arlex/Documents/Project/MyGame/xcode/bin/MyGame/Debug/MyGame.app/Contents/MacOS/MyGame
PostBuild.ext_xxtea.Debug: /Users/arlex/Documents/Project/MyGame/xcode/bin/MyGame/Debug/MyGame.app/Contents/MacOS/MyGame
PostBuild.ext_clipper.Debug: /Users/arlex/Documents/Project/MyGame/xcode/bin/MyGame/Debug/MyGame.app/Contents/MacOS/MyGame
PostBuild.ext_edtaa3func.Debug: /Users/arlex/Documents/Project/MyGame/xcode/bin/MyGame/Debug/MyGame.app/Contents/MacOS/MyGame
PostBuild.ext_convertUTF.Debug: /Users/arlex/Documents/Project/MyGame/xcode/bin/MyGame/Debug/MyGame.app/Contents/MacOS/MyGame
PostBuild.ext_poly2tri.Debug: /Users/arlex/Documents/Project/MyGame/xcode/bin/MyGame/Debug/MyGame.app/Contents/MacOS/MyGame
PostBuild.ext_md5.Debug: /Users/arlex/Documents/Project/MyGame/xcode/bin/MyGame/Debug/MyGame.app/Contents/MacOS/MyGame
PostBuild.ext_unzip.Debug: /Users/arlex/Documents/Project/MyGame/xcode/bin/MyGame/Debug/MyGame.app/Contents/MacOS/MyGame
/Users/arlex/Documents/Project/MyGame/xcode/bin/MyGame/Debug/MyGame.app/Contents/MacOS/MyGame:\
	/Users/arlex/Documents/Project/MyGame/xcode/lib/Debug/libcocos2d.a\
	/Users/arlex/Documents/Project/MyGame/xcode/lib/Debug/libexternal.a\
	/Users/arlex/Documents/Project/MyGame/cocos2d/external/Box2D/prebuilt/mac/libbox2d.a\
	/Users/arlex/Documents/Project/MyGame/cocos2d/external/chipmunk/prebuilt/mac/libchipmunk.a\
	/Users/arlex/Documents/Project/MyGame/cocos2d/external/freetype2/prebuilt/mac/libfreetype.a\
	/Users/arlex/Documents/Project/MyGame/xcode/lib/Debug/libext_recast.a\
	/Users/arlex/Documents/Project/MyGame/cocos2d/external/bullet/prebuilt/mac/libLinearMath.a\
	/Users/arlex/Documents/Project/MyGame/cocos2d/external/bullet/prebuilt/mac/libBulletDynamics.a\
	/Users/arlex/Documents/Project/MyGame/cocos2d/external/bullet/prebuilt/mac/libBulletCollision.a\
	/Users/arlex/Documents/Project/MyGame/cocos2d/external/bullet/prebuilt/mac/libLinearMath.a\
	/Users/arlex/Documents/Project/MyGame/cocos2d/external/bullet/prebuilt/mac/libBulletMultiThreaded.a\
	/Users/arlex/Documents/Project/MyGame/cocos2d/external/bullet/prebuilt/mac/libMiniCL.a\
	/Users/arlex/Documents/Project/MyGame/cocos2d/external/jpeg/prebuilt/mac/libjpeg.a\
	/Users/arlex/Documents/Project/MyGame/cocos2d/external/webp/prebuilt/mac/libwebp.a\
	/Users/arlex/Documents/Project/MyGame/cocos2d/external/websockets/prebuilt/mac/libwebsockets.a\
	/Users/arlex/Documents/Project/MyGame/cocos2d/external/openssl/prebuilt/mac/libssl.a\
	/Users/arlex/Documents/Project/MyGame/cocos2d/external/openssl/prebuilt/mac/libcrypto.a\
	/Users/arlex/Documents/Project/MyGame/cocos2d/external/uv/prebuilt/mac/libuv_a.a\
	/Users/arlex/Documents/Project/MyGame/xcode/lib/Debug/libext_tinyxml2.a\
	/Users/arlex/Documents/Project/MyGame/xcode/lib/Debug/libext_xxhash.a\
	/Users/arlex/Documents/Project/MyGame/xcode/lib/Debug/libext_xxtea.a\
	/Users/arlex/Documents/Project/MyGame/xcode/lib/Debug/libext_clipper.a\
	/Users/arlex/Documents/Project/MyGame/xcode/lib/Debug/libext_edtaa3func.a\
	/Users/arlex/Documents/Project/MyGame/xcode/lib/Debug/libext_convertUTF.a\
	/Users/arlex/Documents/Project/MyGame/xcode/lib/Debug/libext_poly2tri.a\
	/Users/arlex/Documents/Project/MyGame/xcode/lib/Debug/libext_md5.a\
	/Users/arlex/Documents/Project/MyGame/cocos2d/external/curl/prebuilt/mac/libcurl.a\
	/Users/arlex/Documents/Project/MyGame/cocos2d/external/png/prebuilt/mac/libpng.a\
	/Users/arlex/Documents/Project/MyGame/cocos2d/external/glfw3/prebuilt/mac/libglfw3.a\
	/Users/arlex/Documents/Project/MyGame/cocos2d/external/zlib/prebuilt/mac/libz.a\
	/Users/arlex/Documents/Project/MyGame/xcode/lib/Debug/libext_unzip.a\
	/Users/arlex/Documents/Project/MyGame/cocos2d/external/glsl-optimizer/prebuilt/mac/libglcpp-library.a\
	/Users/arlex/Documents/Project/MyGame/cocos2d/external/glsl-optimizer/prebuilt/mac/libglsl_optimizer.a\
	/Users/arlex/Documents/Project/MyGame/cocos2d/external/glsl-optimizer/prebuilt/mac/libmesa.a\
	/usr/lib/libiconv.dylib
	/bin/rm -f /Users/arlex/Documents/Project/MyGame/xcode/bin/MyGame/Debug/MyGame.app/Contents/MacOS/MyGame


PostBuild.cocos2d.Debug:
/Users/arlex/Documents/Project/MyGame/xcode/lib/Debug/libcocos2d.a:
	/bin/rm -f /Users/arlex/Documents/Project/MyGame/xcode/lib/Debug/libcocos2d.a


PostBuild.ext_clipper.Debug:
/Users/arlex/Documents/Project/MyGame/xcode/lib/Debug/libext_clipper.a:
	/bin/rm -f /Users/arlex/Documents/Project/MyGame/xcode/lib/Debug/libext_clipper.a


PostBuild.ext_convertUTF.Debug:
/Users/arlex/Documents/Project/MyGame/xcode/lib/Debug/libext_convertUTF.a:
	/bin/rm -f /Users/arlex/Documents/Project/MyGame/xcode/lib/Debug/libext_convertUTF.a


PostBuild.ext_edtaa3func.Debug:
/Users/arlex/Documents/Project/MyGame/xcode/lib/Debug/libext_edtaa3func.a:
	/bin/rm -f /Users/arlex/Documents/Project/MyGame/xcode/lib/Debug/libext_edtaa3func.a


PostBuild.ext_md5.Debug:
/Users/arlex/Documents/Project/MyGame/xcode/lib/Debug/libext_md5.a:
	/bin/rm -f /Users/arlex/Documents/Project/MyGame/xcode/lib/Debug/libext_md5.a


PostBuild.ext_poly2tri.Debug:
/Users/arlex/Documents/Project/MyGame/xcode/lib/Debug/libext_poly2tri.a:
	/bin/rm -f /Users/arlex/Documents/Project/MyGame/xcode/lib/Debug/libext_poly2tri.a


PostBuild.ext_recast.Debug:
/Users/arlex/Documents/Project/MyGame/xcode/lib/Debug/libext_recast.a:
	/bin/rm -f /Users/arlex/Documents/Project/MyGame/xcode/lib/Debug/libext_recast.a


PostBuild.ext_tinyxml2.Debug:
/Users/arlex/Documents/Project/MyGame/xcode/lib/Debug/libext_tinyxml2.a:
	/bin/rm -f /Users/arlex/Documents/Project/MyGame/xcode/lib/Debug/libext_tinyxml2.a


PostBuild.ext_unzip.Debug:
/Users/arlex/Documents/Project/MyGame/xcode/lib/Debug/libext_unzip.a:
	/bin/rm -f /Users/arlex/Documents/Project/MyGame/xcode/lib/Debug/libext_unzip.a


PostBuild.ext_xxhash.Debug:
/Users/arlex/Documents/Project/MyGame/xcode/lib/Debug/libext_xxhash.a:
	/bin/rm -f /Users/arlex/Documents/Project/MyGame/xcode/lib/Debug/libext_xxhash.a


PostBuild.ext_xxtea.Debug:
/Users/arlex/Documents/Project/MyGame/xcode/lib/Debug/libext_xxtea.a:
	/bin/rm -f /Users/arlex/Documents/Project/MyGame/xcode/lib/Debug/libext_xxtea.a


PostBuild.external.Debug:
/Users/arlex/Documents/Project/MyGame/xcode/lib/Debug/libexternal.a:
	/bin/rm -f /Users/arlex/Documents/Project/MyGame/xcode/lib/Debug/libexternal.a


PostBuild.MyGame.Release:
PostBuild.cocos2d.Release: /Users/arlex/Documents/Project/MyGame/xcode/bin/MyGame/Release/MyGame.app/Contents/MacOS/MyGame
PostBuild.external.Release: /Users/arlex/Documents/Project/MyGame/xcode/bin/MyGame/Release/MyGame.app/Contents/MacOS/MyGame
PostBuild.ext_recast.Release: /Users/arlex/Documents/Project/MyGame/xcode/bin/MyGame/Release/MyGame.app/Contents/MacOS/MyGame
PostBuild.ext_tinyxml2.Release: /Users/arlex/Documents/Project/MyGame/xcode/bin/MyGame/Release/MyGame.app/Contents/MacOS/MyGame
PostBuild.ext_xxhash.Release: /Users/arlex/Documents/Project/MyGame/xcode/bin/MyGame/Release/MyGame.app/Contents/MacOS/MyGame
PostBuild.ext_xxtea.Release: /Users/arlex/Documents/Project/MyGame/xcode/bin/MyGame/Release/MyGame.app/Contents/MacOS/MyGame
PostBuild.ext_clipper.Release: /Users/arlex/Documents/Project/MyGame/xcode/bin/MyGame/Release/MyGame.app/Contents/MacOS/MyGame
PostBuild.ext_edtaa3func.Release: /Users/arlex/Documents/Project/MyGame/xcode/bin/MyGame/Release/MyGame.app/Contents/MacOS/MyGame
PostBuild.ext_convertUTF.Release: /Users/arlex/Documents/Project/MyGame/xcode/bin/MyGame/Release/MyGame.app/Contents/MacOS/MyGame
PostBuild.ext_poly2tri.Release: /Users/arlex/Documents/Project/MyGame/xcode/bin/MyGame/Release/MyGame.app/Contents/MacOS/MyGame
PostBuild.ext_md5.Release: /Users/arlex/Documents/Project/MyGame/xcode/bin/MyGame/Release/MyGame.app/Contents/MacOS/MyGame
PostBuild.ext_unzip.Release: /Users/arlex/Documents/Project/MyGame/xcode/bin/MyGame/Release/MyGame.app/Contents/MacOS/MyGame
/Users/arlex/Documents/Project/MyGame/xcode/bin/MyGame/Release/MyGame.app/Contents/MacOS/MyGame:\
	/Users/arlex/Documents/Project/MyGame/xcode/lib/Release/libcocos2d.a\
	/Users/arlex/Documents/Project/MyGame/xcode/lib/Release/libexternal.a\
	/Users/arlex/Documents/Project/MyGame/cocos2d/external/Box2D/prebuilt/mac/libbox2d.a\
	/Users/arlex/Documents/Project/MyGame/cocos2d/external/chipmunk/prebuilt/mac/libchipmunk.a\
	/Users/arlex/Documents/Project/MyGame/cocos2d/external/freetype2/prebuilt/mac/libfreetype.a\
	/Users/arlex/Documents/Project/MyGame/xcode/lib/Release/libext_recast.a\
	/Users/arlex/Documents/Project/MyGame/cocos2d/external/bullet/prebuilt/mac/libLinearMath.a\
	/Users/arlex/Documents/Project/MyGame/cocos2d/external/bullet/prebuilt/mac/libBulletDynamics.a\
	/Users/arlex/Documents/Project/MyGame/cocos2d/external/bullet/prebuilt/mac/libBulletCollision.a\
	/Users/arlex/Documents/Project/MyGame/cocos2d/external/bullet/prebuilt/mac/libLinearMath.a\
	/Users/arlex/Documents/Project/MyGame/cocos2d/external/bullet/prebuilt/mac/libBulletMultiThreaded.a\
	/Users/arlex/Documents/Project/MyGame/cocos2d/external/bullet/prebuilt/mac/libMiniCL.a\
	/Users/arlex/Documents/Project/MyGame/cocos2d/external/jpeg/prebuilt/mac/libjpeg.a\
	/Users/arlex/Documents/Project/MyGame/cocos2d/external/webp/prebuilt/mac/libwebp.a\
	/Users/arlex/Documents/Project/MyGame/cocos2d/external/websockets/prebuilt/mac/libwebsockets.a\
	/Users/arlex/Documents/Project/MyGame/cocos2d/external/openssl/prebuilt/mac/libssl.a\
	/Users/arlex/Documents/Project/MyGame/cocos2d/external/openssl/prebuilt/mac/libcrypto.a\
	/Users/arlex/Documents/Project/MyGame/cocos2d/external/uv/prebuilt/mac/libuv_a.a\
	/Users/arlex/Documents/Project/MyGame/xcode/lib/Release/libext_tinyxml2.a\
	/Users/arlex/Documents/Project/MyGame/xcode/lib/Release/libext_xxhash.a\
	/Users/arlex/Documents/Project/MyGame/xcode/lib/Release/libext_xxtea.a\
	/Users/arlex/Documents/Project/MyGame/xcode/lib/Release/libext_clipper.a\
	/Users/arlex/Documents/Project/MyGame/xcode/lib/Release/libext_edtaa3func.a\
	/Users/arlex/Documents/Project/MyGame/xcode/lib/Release/libext_convertUTF.a\
	/Users/arlex/Documents/Project/MyGame/xcode/lib/Release/libext_poly2tri.a\
	/Users/arlex/Documents/Project/MyGame/xcode/lib/Release/libext_md5.a\
	/Users/arlex/Documents/Project/MyGame/cocos2d/external/curl/prebuilt/mac/libcurl.a\
	/Users/arlex/Documents/Project/MyGame/cocos2d/external/png/prebuilt/mac/libpng.a\
	/Users/arlex/Documents/Project/MyGame/cocos2d/external/glfw3/prebuilt/mac/libglfw3.a\
	/Users/arlex/Documents/Project/MyGame/cocos2d/external/zlib/prebuilt/mac/libz.a\
	/Users/arlex/Documents/Project/MyGame/xcode/lib/Release/libext_unzip.a\
	/Users/arlex/Documents/Project/MyGame/cocos2d/external/glsl-optimizer/prebuilt/mac/libglcpp-library.a\
	/Users/arlex/Documents/Project/MyGame/cocos2d/external/glsl-optimizer/prebuilt/mac/libglsl_optimizer.a\
	/Users/arlex/Documents/Project/MyGame/cocos2d/external/glsl-optimizer/prebuilt/mac/libmesa.a\
	/usr/lib/libiconv.dylib
	/bin/rm -f /Users/arlex/Documents/Project/MyGame/xcode/bin/MyGame/Release/MyGame.app/Contents/MacOS/MyGame


PostBuild.cocos2d.Release:
/Users/arlex/Documents/Project/MyGame/xcode/lib/Release/libcocos2d.a:
	/bin/rm -f /Users/arlex/Documents/Project/MyGame/xcode/lib/Release/libcocos2d.a


PostBuild.ext_clipper.Release:
/Users/arlex/Documents/Project/MyGame/xcode/lib/Release/libext_clipper.a:
	/bin/rm -f /Users/arlex/Documents/Project/MyGame/xcode/lib/Release/libext_clipper.a


PostBuild.ext_convertUTF.Release:
/Users/arlex/Documents/Project/MyGame/xcode/lib/Release/libext_convertUTF.a:
	/bin/rm -f /Users/arlex/Documents/Project/MyGame/xcode/lib/Release/libext_convertUTF.a


PostBuild.ext_edtaa3func.Release:
/Users/arlex/Documents/Project/MyGame/xcode/lib/Release/libext_edtaa3func.a:
	/bin/rm -f /Users/arlex/Documents/Project/MyGame/xcode/lib/Release/libext_edtaa3func.a


PostBuild.ext_md5.Release:
/Users/arlex/Documents/Project/MyGame/xcode/lib/Release/libext_md5.a:
	/bin/rm -f /Users/arlex/Documents/Project/MyGame/xcode/lib/Release/libext_md5.a


PostBuild.ext_poly2tri.Release:
/Users/arlex/Documents/Project/MyGame/xcode/lib/Release/libext_poly2tri.a:
	/bin/rm -f /Users/arlex/Documents/Project/MyGame/xcode/lib/Release/libext_poly2tri.a


PostBuild.ext_recast.Release:
/Users/arlex/Documents/Project/MyGame/xcode/lib/Release/libext_recast.a:
	/bin/rm -f /Users/arlex/Documents/Project/MyGame/xcode/lib/Release/libext_recast.a


PostBuild.ext_tinyxml2.Release:
/Users/arlex/Documents/Project/MyGame/xcode/lib/Release/libext_tinyxml2.a:
	/bin/rm -f /Users/arlex/Documents/Project/MyGame/xcode/lib/Release/libext_tinyxml2.a


PostBuild.ext_unzip.Release:
/Users/arlex/Documents/Project/MyGame/xcode/lib/Release/libext_unzip.a:
	/bin/rm -f /Users/arlex/Documents/Project/MyGame/xcode/lib/Release/libext_unzip.a


PostBuild.ext_xxhash.Release:
/Users/arlex/Documents/Project/MyGame/xcode/lib/Release/libext_xxhash.a:
	/bin/rm -f /Users/arlex/Documents/Project/MyGame/xcode/lib/Release/libext_xxhash.a


PostBuild.ext_xxtea.Release:
/Users/arlex/Documents/Project/MyGame/xcode/lib/Release/libext_xxtea.a:
	/bin/rm -f /Users/arlex/Documents/Project/MyGame/xcode/lib/Release/libext_xxtea.a


PostBuild.external.Release:
/Users/arlex/Documents/Project/MyGame/xcode/lib/Release/libexternal.a:
	/bin/rm -f /Users/arlex/Documents/Project/MyGame/xcode/lib/Release/libexternal.a


PostBuild.MyGame.MinSizeRel:
PostBuild.cocos2d.MinSizeRel: /Users/arlex/Documents/Project/MyGame/xcode/bin/MyGame/MinSizeRel/MyGame.app/Contents/MacOS/MyGame
PostBuild.external.MinSizeRel: /Users/arlex/Documents/Project/MyGame/xcode/bin/MyGame/MinSizeRel/MyGame.app/Contents/MacOS/MyGame
PostBuild.ext_recast.MinSizeRel: /Users/arlex/Documents/Project/MyGame/xcode/bin/MyGame/MinSizeRel/MyGame.app/Contents/MacOS/MyGame
PostBuild.ext_tinyxml2.MinSizeRel: /Users/arlex/Documents/Project/MyGame/xcode/bin/MyGame/MinSizeRel/MyGame.app/Contents/MacOS/MyGame
PostBuild.ext_xxhash.MinSizeRel: /Users/arlex/Documents/Project/MyGame/xcode/bin/MyGame/MinSizeRel/MyGame.app/Contents/MacOS/MyGame
PostBuild.ext_xxtea.MinSizeRel: /Users/arlex/Documents/Project/MyGame/xcode/bin/MyGame/MinSizeRel/MyGame.app/Contents/MacOS/MyGame
PostBuild.ext_clipper.MinSizeRel: /Users/arlex/Documents/Project/MyGame/xcode/bin/MyGame/MinSizeRel/MyGame.app/Contents/MacOS/MyGame
PostBuild.ext_edtaa3func.MinSizeRel: /Users/arlex/Documents/Project/MyGame/xcode/bin/MyGame/MinSizeRel/MyGame.app/Contents/MacOS/MyGame
PostBuild.ext_convertUTF.MinSizeRel: /Users/arlex/Documents/Project/MyGame/xcode/bin/MyGame/MinSizeRel/MyGame.app/Contents/MacOS/MyGame
PostBuild.ext_poly2tri.MinSizeRel: /Users/arlex/Documents/Project/MyGame/xcode/bin/MyGame/MinSizeRel/MyGame.app/Contents/MacOS/MyGame
PostBuild.ext_md5.MinSizeRel: /Users/arlex/Documents/Project/MyGame/xcode/bin/MyGame/MinSizeRel/MyGame.app/Contents/MacOS/MyGame
PostBuild.ext_unzip.MinSizeRel: /Users/arlex/Documents/Project/MyGame/xcode/bin/MyGame/MinSizeRel/MyGame.app/Contents/MacOS/MyGame
/Users/arlex/Documents/Project/MyGame/xcode/bin/MyGame/MinSizeRel/MyGame.app/Contents/MacOS/MyGame:\
	/Users/arlex/Documents/Project/MyGame/xcode/lib/MinSizeRel/libcocos2d.a\
	/Users/arlex/Documents/Project/MyGame/xcode/lib/MinSizeRel/libexternal.a\
	/Users/arlex/Documents/Project/MyGame/cocos2d/external/Box2D/prebuilt/mac/libbox2d.a\
	/Users/arlex/Documents/Project/MyGame/cocos2d/external/chipmunk/prebuilt/mac/libchipmunk.a\
	/Users/arlex/Documents/Project/MyGame/cocos2d/external/freetype2/prebuilt/mac/libfreetype.a\
	/Users/arlex/Documents/Project/MyGame/xcode/lib/MinSizeRel/libext_recast.a\
	/Users/arlex/Documents/Project/MyGame/cocos2d/external/bullet/prebuilt/mac/libLinearMath.a\
	/Users/arlex/Documents/Project/MyGame/cocos2d/external/bullet/prebuilt/mac/libBulletDynamics.a\
	/Users/arlex/Documents/Project/MyGame/cocos2d/external/bullet/prebuilt/mac/libBulletCollision.a\
	/Users/arlex/Documents/Project/MyGame/cocos2d/external/bullet/prebuilt/mac/libLinearMath.a\
	/Users/arlex/Documents/Project/MyGame/cocos2d/external/bullet/prebuilt/mac/libBulletMultiThreaded.a\
	/Users/arlex/Documents/Project/MyGame/cocos2d/external/bullet/prebuilt/mac/libMiniCL.a\
	/Users/arlex/Documents/Project/MyGame/cocos2d/external/jpeg/prebuilt/mac/libjpeg.a\
	/Users/arlex/Documents/Project/MyGame/cocos2d/external/webp/prebuilt/mac/libwebp.a\
	/Users/arlex/Documents/Project/MyGame/cocos2d/external/websockets/prebuilt/mac/libwebsockets.a\
	/Users/arlex/Documents/Project/MyGame/cocos2d/external/openssl/prebuilt/mac/libssl.a\
	/Users/arlex/Documents/Project/MyGame/cocos2d/external/openssl/prebuilt/mac/libcrypto.a\
	/Users/arlex/Documents/Project/MyGame/cocos2d/external/uv/prebuilt/mac/libuv_a.a\
	/Users/arlex/Documents/Project/MyGame/xcode/lib/MinSizeRel/libext_tinyxml2.a\
	/Users/arlex/Documents/Project/MyGame/xcode/lib/MinSizeRel/libext_xxhash.a\
	/Users/arlex/Documents/Project/MyGame/xcode/lib/MinSizeRel/libext_xxtea.a\
	/Users/arlex/Documents/Project/MyGame/xcode/lib/MinSizeRel/libext_clipper.a\
	/Users/arlex/Documents/Project/MyGame/xcode/lib/MinSizeRel/libext_edtaa3func.a\
	/Users/arlex/Documents/Project/MyGame/xcode/lib/MinSizeRel/libext_convertUTF.a\
	/Users/arlex/Documents/Project/MyGame/xcode/lib/MinSizeRel/libext_poly2tri.a\
	/Users/arlex/Documents/Project/MyGame/xcode/lib/MinSizeRel/libext_md5.a\
	/Users/arlex/Documents/Project/MyGame/cocos2d/external/curl/prebuilt/mac/libcurl.a\
	/Users/arlex/Documents/Project/MyGame/cocos2d/external/png/prebuilt/mac/libpng.a\
	/Users/arlex/Documents/Project/MyGame/cocos2d/external/glfw3/prebuilt/mac/libglfw3.a\
	/Users/arlex/Documents/Project/MyGame/cocos2d/external/zlib/prebuilt/mac/libz.a\
	/Users/arlex/Documents/Project/MyGame/xcode/lib/MinSizeRel/libext_unzip.a\
	/Users/arlex/Documents/Project/MyGame/cocos2d/external/glsl-optimizer/prebuilt/mac/libglcpp-library.a\
	/Users/arlex/Documents/Project/MyGame/cocos2d/external/glsl-optimizer/prebuilt/mac/libglsl_optimizer.a\
	/Users/arlex/Documents/Project/MyGame/cocos2d/external/glsl-optimizer/prebuilt/mac/libmesa.a\
	/usr/lib/libiconv.dylib
	/bin/rm -f /Users/arlex/Documents/Project/MyGame/xcode/bin/MyGame/MinSizeRel/MyGame.app/Contents/MacOS/MyGame


PostBuild.cocos2d.MinSizeRel:
/Users/arlex/Documents/Project/MyGame/xcode/lib/MinSizeRel/libcocos2d.a:
	/bin/rm -f /Users/arlex/Documents/Project/MyGame/xcode/lib/MinSizeRel/libcocos2d.a


PostBuild.ext_clipper.MinSizeRel:
/Users/arlex/Documents/Project/MyGame/xcode/lib/MinSizeRel/libext_clipper.a:
	/bin/rm -f /Users/arlex/Documents/Project/MyGame/xcode/lib/MinSizeRel/libext_clipper.a


PostBuild.ext_convertUTF.MinSizeRel:
/Users/arlex/Documents/Project/MyGame/xcode/lib/MinSizeRel/libext_convertUTF.a:
	/bin/rm -f /Users/arlex/Documents/Project/MyGame/xcode/lib/MinSizeRel/libext_convertUTF.a


PostBuild.ext_edtaa3func.MinSizeRel:
/Users/arlex/Documents/Project/MyGame/xcode/lib/MinSizeRel/libext_edtaa3func.a:
	/bin/rm -f /Users/arlex/Documents/Project/MyGame/xcode/lib/MinSizeRel/libext_edtaa3func.a


PostBuild.ext_md5.MinSizeRel:
/Users/arlex/Documents/Project/MyGame/xcode/lib/MinSizeRel/libext_md5.a:
	/bin/rm -f /Users/arlex/Documents/Project/MyGame/xcode/lib/MinSizeRel/libext_md5.a


PostBuild.ext_poly2tri.MinSizeRel:
/Users/arlex/Documents/Project/MyGame/xcode/lib/MinSizeRel/libext_poly2tri.a:
	/bin/rm -f /Users/arlex/Documents/Project/MyGame/xcode/lib/MinSizeRel/libext_poly2tri.a


PostBuild.ext_recast.MinSizeRel:
/Users/arlex/Documents/Project/MyGame/xcode/lib/MinSizeRel/libext_recast.a:
	/bin/rm -f /Users/arlex/Documents/Project/MyGame/xcode/lib/MinSizeRel/libext_recast.a


PostBuild.ext_tinyxml2.MinSizeRel:
/Users/arlex/Documents/Project/MyGame/xcode/lib/MinSizeRel/libext_tinyxml2.a:
	/bin/rm -f /Users/arlex/Documents/Project/MyGame/xcode/lib/MinSizeRel/libext_tinyxml2.a


PostBuild.ext_unzip.MinSizeRel:
/Users/arlex/Documents/Project/MyGame/xcode/lib/MinSizeRel/libext_unzip.a:
	/bin/rm -f /Users/arlex/Documents/Project/MyGame/xcode/lib/MinSizeRel/libext_unzip.a


PostBuild.ext_xxhash.MinSizeRel:
/Users/arlex/Documents/Project/MyGame/xcode/lib/MinSizeRel/libext_xxhash.a:
	/bin/rm -f /Users/arlex/Documents/Project/MyGame/xcode/lib/MinSizeRel/libext_xxhash.a


PostBuild.ext_xxtea.MinSizeRel:
/Users/arlex/Documents/Project/MyGame/xcode/lib/MinSizeRel/libext_xxtea.a:
	/bin/rm -f /Users/arlex/Documents/Project/MyGame/xcode/lib/MinSizeRel/libext_xxtea.a


PostBuild.external.MinSizeRel:
/Users/arlex/Documents/Project/MyGame/xcode/lib/MinSizeRel/libexternal.a:
	/bin/rm -f /Users/arlex/Documents/Project/MyGame/xcode/lib/MinSizeRel/libexternal.a


PostBuild.MyGame.RelWithDebInfo:
PostBuild.cocos2d.RelWithDebInfo: /Users/arlex/Documents/Project/MyGame/xcode/bin/MyGame/RelWithDebInfo/MyGame.app/Contents/MacOS/MyGame
PostBuild.external.RelWithDebInfo: /Users/arlex/Documents/Project/MyGame/xcode/bin/MyGame/RelWithDebInfo/MyGame.app/Contents/MacOS/MyGame
PostBuild.ext_recast.RelWithDebInfo: /Users/arlex/Documents/Project/MyGame/xcode/bin/MyGame/RelWithDebInfo/MyGame.app/Contents/MacOS/MyGame
PostBuild.ext_tinyxml2.RelWithDebInfo: /Users/arlex/Documents/Project/MyGame/xcode/bin/MyGame/RelWithDebInfo/MyGame.app/Contents/MacOS/MyGame
PostBuild.ext_xxhash.RelWithDebInfo: /Users/arlex/Documents/Project/MyGame/xcode/bin/MyGame/RelWithDebInfo/MyGame.app/Contents/MacOS/MyGame
PostBuild.ext_xxtea.RelWithDebInfo: /Users/arlex/Documents/Project/MyGame/xcode/bin/MyGame/RelWithDebInfo/MyGame.app/Contents/MacOS/MyGame
PostBuild.ext_clipper.RelWithDebInfo: /Users/arlex/Documents/Project/MyGame/xcode/bin/MyGame/RelWithDebInfo/MyGame.app/Contents/MacOS/MyGame
PostBuild.ext_edtaa3func.RelWithDebInfo: /Users/arlex/Documents/Project/MyGame/xcode/bin/MyGame/RelWithDebInfo/MyGame.app/Contents/MacOS/MyGame
PostBuild.ext_convertUTF.RelWithDebInfo: /Users/arlex/Documents/Project/MyGame/xcode/bin/MyGame/RelWithDebInfo/MyGame.app/Contents/MacOS/MyGame
PostBuild.ext_poly2tri.RelWithDebInfo: /Users/arlex/Documents/Project/MyGame/xcode/bin/MyGame/RelWithDebInfo/MyGame.app/Contents/MacOS/MyGame
PostBuild.ext_md5.RelWithDebInfo: /Users/arlex/Documents/Project/MyGame/xcode/bin/MyGame/RelWithDebInfo/MyGame.app/Contents/MacOS/MyGame
PostBuild.ext_unzip.RelWithDebInfo: /Users/arlex/Documents/Project/MyGame/xcode/bin/MyGame/RelWithDebInfo/MyGame.app/Contents/MacOS/MyGame
/Users/arlex/Documents/Project/MyGame/xcode/bin/MyGame/RelWithDebInfo/MyGame.app/Contents/MacOS/MyGame:\
	/Users/arlex/Documents/Project/MyGame/xcode/lib/RelWithDebInfo/libcocos2d.a\
	/Users/arlex/Documents/Project/MyGame/xcode/lib/RelWithDebInfo/libexternal.a\
	/Users/arlex/Documents/Project/MyGame/cocos2d/external/Box2D/prebuilt/mac/libbox2d.a\
	/Users/arlex/Documents/Project/MyGame/cocos2d/external/chipmunk/prebuilt/mac/libchipmunk.a\
	/Users/arlex/Documents/Project/MyGame/cocos2d/external/freetype2/prebuilt/mac/libfreetype.a\
	/Users/arlex/Documents/Project/MyGame/xcode/lib/RelWithDebInfo/libext_recast.a\
	/Users/arlex/Documents/Project/MyGame/cocos2d/external/bullet/prebuilt/mac/libLinearMath.a\
	/Users/arlex/Documents/Project/MyGame/cocos2d/external/bullet/prebuilt/mac/libBulletDynamics.a\
	/Users/arlex/Documents/Project/MyGame/cocos2d/external/bullet/prebuilt/mac/libBulletCollision.a\
	/Users/arlex/Documents/Project/MyGame/cocos2d/external/bullet/prebuilt/mac/libLinearMath.a\
	/Users/arlex/Documents/Project/MyGame/cocos2d/external/bullet/prebuilt/mac/libBulletMultiThreaded.a\
	/Users/arlex/Documents/Project/MyGame/cocos2d/external/bullet/prebuilt/mac/libMiniCL.a\
	/Users/arlex/Documents/Project/MyGame/cocos2d/external/jpeg/prebuilt/mac/libjpeg.a\
	/Users/arlex/Documents/Project/MyGame/cocos2d/external/webp/prebuilt/mac/libwebp.a\
	/Users/arlex/Documents/Project/MyGame/cocos2d/external/websockets/prebuilt/mac/libwebsockets.a\
	/Users/arlex/Documents/Project/MyGame/cocos2d/external/openssl/prebuilt/mac/libssl.a\
	/Users/arlex/Documents/Project/MyGame/cocos2d/external/openssl/prebuilt/mac/libcrypto.a\
	/Users/arlex/Documents/Project/MyGame/cocos2d/external/uv/prebuilt/mac/libuv_a.a\
	/Users/arlex/Documents/Project/MyGame/xcode/lib/RelWithDebInfo/libext_tinyxml2.a\
	/Users/arlex/Documents/Project/MyGame/xcode/lib/RelWithDebInfo/libext_xxhash.a\
	/Users/arlex/Documents/Project/MyGame/xcode/lib/RelWithDebInfo/libext_xxtea.a\
	/Users/arlex/Documents/Project/MyGame/xcode/lib/RelWithDebInfo/libext_clipper.a\
	/Users/arlex/Documents/Project/MyGame/xcode/lib/RelWithDebInfo/libext_edtaa3func.a\
	/Users/arlex/Documents/Project/MyGame/xcode/lib/RelWithDebInfo/libext_convertUTF.a\
	/Users/arlex/Documents/Project/MyGame/xcode/lib/RelWithDebInfo/libext_poly2tri.a\
	/Users/arlex/Documents/Project/MyGame/xcode/lib/RelWithDebInfo/libext_md5.a\
	/Users/arlex/Documents/Project/MyGame/cocos2d/external/curl/prebuilt/mac/libcurl.a\
	/Users/arlex/Documents/Project/MyGame/cocos2d/external/png/prebuilt/mac/libpng.a\
	/Users/arlex/Documents/Project/MyGame/cocos2d/external/glfw3/prebuilt/mac/libglfw3.a\
	/Users/arlex/Documents/Project/MyGame/cocos2d/external/zlib/prebuilt/mac/libz.a\
	/Users/arlex/Documents/Project/MyGame/xcode/lib/RelWithDebInfo/libext_unzip.a\
	/Users/arlex/Documents/Project/MyGame/cocos2d/external/glsl-optimizer/prebuilt/mac/libglcpp-library.a\
	/Users/arlex/Documents/Project/MyGame/cocos2d/external/glsl-optimizer/prebuilt/mac/libglsl_optimizer.a\
	/Users/arlex/Documents/Project/MyGame/cocos2d/external/glsl-optimizer/prebuilt/mac/libmesa.a\
	/usr/lib/libiconv.dylib
	/bin/rm -f /Users/arlex/Documents/Project/MyGame/xcode/bin/MyGame/RelWithDebInfo/MyGame.app/Contents/MacOS/MyGame


PostBuild.cocos2d.RelWithDebInfo:
/Users/arlex/Documents/Project/MyGame/xcode/lib/RelWithDebInfo/libcocos2d.a:
	/bin/rm -f /Users/arlex/Documents/Project/MyGame/xcode/lib/RelWithDebInfo/libcocos2d.a


PostBuild.ext_clipper.RelWithDebInfo:
/Users/arlex/Documents/Project/MyGame/xcode/lib/RelWithDebInfo/libext_clipper.a:
	/bin/rm -f /Users/arlex/Documents/Project/MyGame/xcode/lib/RelWithDebInfo/libext_clipper.a


PostBuild.ext_convertUTF.RelWithDebInfo:
/Users/arlex/Documents/Project/MyGame/xcode/lib/RelWithDebInfo/libext_convertUTF.a:
	/bin/rm -f /Users/arlex/Documents/Project/MyGame/xcode/lib/RelWithDebInfo/libext_convertUTF.a


PostBuild.ext_edtaa3func.RelWithDebInfo:
/Users/arlex/Documents/Project/MyGame/xcode/lib/RelWithDebInfo/libext_edtaa3func.a:
	/bin/rm -f /Users/arlex/Documents/Project/MyGame/xcode/lib/RelWithDebInfo/libext_edtaa3func.a


PostBuild.ext_md5.RelWithDebInfo:
/Users/arlex/Documents/Project/MyGame/xcode/lib/RelWithDebInfo/libext_md5.a:
	/bin/rm -f /Users/arlex/Documents/Project/MyGame/xcode/lib/RelWithDebInfo/libext_md5.a


PostBuild.ext_poly2tri.RelWithDebInfo:
/Users/arlex/Documents/Project/MyGame/xcode/lib/RelWithDebInfo/libext_poly2tri.a:
	/bin/rm -f /Users/arlex/Documents/Project/MyGame/xcode/lib/RelWithDebInfo/libext_poly2tri.a


PostBuild.ext_recast.RelWithDebInfo:
/Users/arlex/Documents/Project/MyGame/xcode/lib/RelWithDebInfo/libext_recast.a:
	/bin/rm -f /Users/arlex/Documents/Project/MyGame/xcode/lib/RelWithDebInfo/libext_recast.a


PostBuild.ext_tinyxml2.RelWithDebInfo:
/Users/arlex/Documents/Project/MyGame/xcode/lib/RelWithDebInfo/libext_tinyxml2.a:
	/bin/rm -f /Users/arlex/Documents/Project/MyGame/xcode/lib/RelWithDebInfo/libext_tinyxml2.a


PostBuild.ext_unzip.RelWithDebInfo:
/Users/arlex/Documents/Project/MyGame/xcode/lib/RelWithDebInfo/libext_unzip.a:
	/bin/rm -f /Users/arlex/Documents/Project/MyGame/xcode/lib/RelWithDebInfo/libext_unzip.a


PostBuild.ext_xxhash.RelWithDebInfo:
/Users/arlex/Documents/Project/MyGame/xcode/lib/RelWithDebInfo/libext_xxhash.a:
	/bin/rm -f /Users/arlex/Documents/Project/MyGame/xcode/lib/RelWithDebInfo/libext_xxhash.a


PostBuild.ext_xxtea.RelWithDebInfo:
/Users/arlex/Documents/Project/MyGame/xcode/lib/RelWithDebInfo/libext_xxtea.a:
	/bin/rm -f /Users/arlex/Documents/Project/MyGame/xcode/lib/RelWithDebInfo/libext_xxtea.a


PostBuild.external.RelWithDebInfo:
/Users/arlex/Documents/Project/MyGame/xcode/lib/RelWithDebInfo/libexternal.a:
	/bin/rm -f /Users/arlex/Documents/Project/MyGame/xcode/lib/RelWithDebInfo/libexternal.a




# For each target create a dummy ruleso the target does not have to exist
/Users/arlex/Documents/Project/MyGame/cocos2d/external/Box2D/prebuilt/mac/libbox2d.a:
/Users/arlex/Documents/Project/MyGame/cocos2d/external/bullet/prebuilt/mac/libBulletCollision.a:
/Users/arlex/Documents/Project/MyGame/cocos2d/external/bullet/prebuilt/mac/libBulletDynamics.a:
/Users/arlex/Documents/Project/MyGame/cocos2d/external/bullet/prebuilt/mac/libBulletMultiThreaded.a:
/Users/arlex/Documents/Project/MyGame/cocos2d/external/bullet/prebuilt/mac/libLinearMath.a:
/Users/arlex/Documents/Project/MyGame/cocos2d/external/bullet/prebuilt/mac/libMiniCL.a:
/Users/arlex/Documents/Project/MyGame/cocos2d/external/chipmunk/prebuilt/mac/libchipmunk.a:
/Users/arlex/Documents/Project/MyGame/cocos2d/external/curl/prebuilt/mac/libcurl.a:
/Users/arlex/Documents/Project/MyGame/cocos2d/external/freetype2/prebuilt/mac/libfreetype.a:
/Users/arlex/Documents/Project/MyGame/cocos2d/external/glfw3/prebuilt/mac/libglfw3.a:
/Users/arlex/Documents/Project/MyGame/cocos2d/external/glsl-optimizer/prebuilt/mac/libglcpp-library.a:
/Users/arlex/Documents/Project/MyGame/cocos2d/external/glsl-optimizer/prebuilt/mac/libglsl_optimizer.a:
/Users/arlex/Documents/Project/MyGame/cocos2d/external/glsl-optimizer/prebuilt/mac/libmesa.a:
/Users/arlex/Documents/Project/MyGame/cocos2d/external/jpeg/prebuilt/mac/libjpeg.a:
/Users/arlex/Documents/Project/MyGame/cocos2d/external/openssl/prebuilt/mac/libcrypto.a:
/Users/arlex/Documents/Project/MyGame/cocos2d/external/openssl/prebuilt/mac/libssl.a:
/Users/arlex/Documents/Project/MyGame/cocos2d/external/png/prebuilt/mac/libpng.a:
/Users/arlex/Documents/Project/MyGame/cocos2d/external/uv/prebuilt/mac/libuv_a.a:
/Users/arlex/Documents/Project/MyGame/cocos2d/external/webp/prebuilt/mac/libwebp.a:
/Users/arlex/Documents/Project/MyGame/cocos2d/external/websockets/prebuilt/mac/libwebsockets.a:
/Users/arlex/Documents/Project/MyGame/cocos2d/external/zlib/prebuilt/mac/libz.a:
/Users/arlex/Documents/Project/MyGame/xcode/lib/Debug/libcocos2d.a:
/Users/arlex/Documents/Project/MyGame/xcode/lib/Debug/libext_clipper.a:
/Users/arlex/Documents/Project/MyGame/xcode/lib/Debug/libext_convertUTF.a:
/Users/arlex/Documents/Project/MyGame/xcode/lib/Debug/libext_edtaa3func.a:
/Users/arlex/Documents/Project/MyGame/xcode/lib/Debug/libext_md5.a:
/Users/arlex/Documents/Project/MyGame/xcode/lib/Debug/libext_poly2tri.a:
/Users/arlex/Documents/Project/MyGame/xcode/lib/Debug/libext_recast.a:
/Users/arlex/Documents/Project/MyGame/xcode/lib/Debug/libext_tinyxml2.a:
/Users/arlex/Documents/Project/MyGame/xcode/lib/Debug/libext_unzip.a:
/Users/arlex/Documents/Project/MyGame/xcode/lib/Debug/libext_xxhash.a:
/Users/arlex/Documents/Project/MyGame/xcode/lib/Debug/libext_xxtea.a:
/Users/arlex/Documents/Project/MyGame/xcode/lib/Debug/libexternal.a:
/Users/arlex/Documents/Project/MyGame/xcode/lib/MinSizeRel/libcocos2d.a:
/Users/arlex/Documents/Project/MyGame/xcode/lib/MinSizeRel/libext_clipper.a:
/Users/arlex/Documents/Project/MyGame/xcode/lib/MinSizeRel/libext_convertUTF.a:
/Users/arlex/Documents/Project/MyGame/xcode/lib/MinSizeRel/libext_edtaa3func.a:
/Users/arlex/Documents/Project/MyGame/xcode/lib/MinSizeRel/libext_md5.a:
/Users/arlex/Documents/Project/MyGame/xcode/lib/MinSizeRel/libext_poly2tri.a:
/Users/arlex/Documents/Project/MyGame/xcode/lib/MinSizeRel/libext_recast.a:
/Users/arlex/Documents/Project/MyGame/xcode/lib/MinSizeRel/libext_tinyxml2.a:
/Users/arlex/Documents/Project/MyGame/xcode/lib/MinSizeRel/libext_unzip.a:
/Users/arlex/Documents/Project/MyGame/xcode/lib/MinSizeRel/libext_xxhash.a:
/Users/arlex/Documents/Project/MyGame/xcode/lib/MinSizeRel/libext_xxtea.a:
/Users/arlex/Documents/Project/MyGame/xcode/lib/MinSizeRel/libexternal.a:
/Users/arlex/Documents/Project/MyGame/xcode/lib/RelWithDebInfo/libcocos2d.a:
/Users/arlex/Documents/Project/MyGame/xcode/lib/RelWithDebInfo/libext_clipper.a:
/Users/arlex/Documents/Project/MyGame/xcode/lib/RelWithDebInfo/libext_convertUTF.a:
/Users/arlex/Documents/Project/MyGame/xcode/lib/RelWithDebInfo/libext_edtaa3func.a:
/Users/arlex/Documents/Project/MyGame/xcode/lib/RelWithDebInfo/libext_md5.a:
/Users/arlex/Documents/Project/MyGame/xcode/lib/RelWithDebInfo/libext_poly2tri.a:
/Users/arlex/Documents/Project/MyGame/xcode/lib/RelWithDebInfo/libext_recast.a:
/Users/arlex/Documents/Project/MyGame/xcode/lib/RelWithDebInfo/libext_tinyxml2.a:
/Users/arlex/Documents/Project/MyGame/xcode/lib/RelWithDebInfo/libext_unzip.a:
/Users/arlex/Documents/Project/MyGame/xcode/lib/RelWithDebInfo/libext_xxhash.a:
/Users/arlex/Documents/Project/MyGame/xcode/lib/RelWithDebInfo/libext_xxtea.a:
/Users/arlex/Documents/Project/MyGame/xcode/lib/RelWithDebInfo/libexternal.a:
/Users/arlex/Documents/Project/MyGame/xcode/lib/Release/libcocos2d.a:
/Users/arlex/Documents/Project/MyGame/xcode/lib/Release/libext_clipper.a:
/Users/arlex/Documents/Project/MyGame/xcode/lib/Release/libext_convertUTF.a:
/Users/arlex/Documents/Project/MyGame/xcode/lib/Release/libext_edtaa3func.a:
/Users/arlex/Documents/Project/MyGame/xcode/lib/Release/libext_md5.a:
/Users/arlex/Documents/Project/MyGame/xcode/lib/Release/libext_poly2tri.a:
/Users/arlex/Documents/Project/MyGame/xcode/lib/Release/libext_recast.a:
/Users/arlex/Documents/Project/MyGame/xcode/lib/Release/libext_tinyxml2.a:
/Users/arlex/Documents/Project/MyGame/xcode/lib/Release/libext_unzip.a:
/Users/arlex/Documents/Project/MyGame/xcode/lib/Release/libext_xxhash.a:
/Users/arlex/Documents/Project/MyGame/xcode/lib/Release/libext_xxtea.a:
/Users/arlex/Documents/Project/MyGame/xcode/lib/Release/libexternal.a:
/usr/lib/libiconv.dylib:
