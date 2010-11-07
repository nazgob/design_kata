#include <iostream>
#include <iterator>
#include <vector>
#include <string>
#include <algorithm>

class MessageAssembler
{
  public:
    virtual void createHeader() = 0;
    virtual void createBody() = 0;
    virtual void createFooter() = 0;

    void putMessage(const std::string& msg) {mMesssage.push_back(msg);}
    const std::vector<std::string>& getMessage() const {return mMesssage;}

  private:
    std::vector<std::string> mMesssage;
};

class XmlMessageAssembler : public MessageAssembler
{
  public:
    virtual void createHeader()
    {
      putMessage("<header>foobar_header</header>");
    }
    virtual void createBody()
    {
      putMessage("<body>foo</body>");
      putMessage("<body>bar</body>");
      putMessage("<body>foobar</body>");
    }
    virtual void createFooter()
    { 
      putMessage("<footer>foobar_footer</footer>");
    }
};

class TxtMessageAssembler : public MessageAssembler
{
  public:
    virtual void createHeader()
    {
      putMessage("foobar_header");
    }
    virtual void createBody()
    {
      putMessage("foo");
      putMessage("bar");
      putMessage("foobar");
    }
    virtual void createFooter()
    { 
      putMessage("foobar_footer");
    }
};

class MessageBuilder
{
  public:
    const std::vector<std::string>& buildMessage(MessageAssembler* assembler) const
    {
      assembler->createHeader();
      assembler->createBody();
      assembler->createFooter();

      return assembler->getMessage();
    }
};

int main()
{
  std::cout << "Builder GoF Kata" << std::endl;

  MessageBuilder messageBuilder;
  std::vector<std::string> result;
  MessageAssembler* messageAssembler = NULL;

  messageAssembler = new XmlMessageAssembler();
  result = messageBuilder.buildMessage(messageAssembler);
  std::copy(result.begin(), result.end(), std::ostream_iterator<std::string>(std::cout, "\n")); // love it or hate!
  delete messageAssembler; messageAssembler = NULL;

  std::cout << std::endl;

  messageAssembler = new TxtMessageAssembler();
  result = messageBuilder.buildMessage(messageAssembler);
  std::copy(result.begin(), result.end(), std::ostream_iterator<std::string>(std::cout, "\n")); // love it or hate!
  delete messageAssembler; messageAssembler = NULL;
} 

