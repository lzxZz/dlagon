// Copyright 2018, lzxZz
// e-mail : 616281384@qq.com
// last modified in 2019.1.5

/**
 * 声明Mime_Type类,用于处理http请求中mime类型相关的部分
**/

#ifndef DLAGON_HTTP_MIME_TYPE_H_
#define DLAGON_HTTP_MIME_TYPE_H_

#include <string>

namespace dlagon{

namespace http
{
   // 暂时留下
//    enum class MimeType{
//       VideoX_msvideo,// AVI,
//       ImageBmp, //BMP,
//       TestCss, //CSS,
//       ApplicationMsword, //DOC,
//       ImageGif, //GIF,
//       ApplicationX_gzip,// GZ,
//       ApplicationX_gtar, // GTAR,
//       TextPlain,// H,TXT
//       TextHtml, // HTM, HTML
//       TextWebViewHtml, // HTT,
//       ImageX_ico,// ICO,
//       ImageJpeg, // JPE,JPEG, JPG
//       ApplicationX_javascript, // JS,
//       ApplicationX_latex, // LATEX,
//       AudioMpeg, // MP3,
//       VideoMpeg, // MP4,
//       ApplicationPdf, // PDF,
//       TextRichText, // RTX,
//       ApplicationX_sh, // SH,
//       ImageSvg_xml, //SVG,       这里对应的为image/svg+xml,由于不能在代码中编写+因此替换为下划线
//       ApplicationX_tar, // TAR,
//       ApplicationX_compressed, // TGZ,
//       AudioX_wav, //WAV,
//       ApplicationVnd_MS_excel, // XLS,
//       ApplicationZip // ZIP,
//    };

   class MimeType{
   public:
      
      // 将后缀名转化为指定的 Content-Type值
      // 参数由于实现原因,不能使用const,也不能使用引用
      static const std::string SuffixToMimeType(std::string suffix);    
   private:
      // 暂时无用
      static const bool Accept();// 判断请求对象的后缀是否是属于可接受的范围 
   };
} // http


} // namespace dlagon

#endif //DLAGON_HTTP_MIME_TYPE_H_