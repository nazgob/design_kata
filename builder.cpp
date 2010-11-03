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

    const std::vector<std::string>& getMessage() const {return mMesssage;}

  protected:
    std::vector<std::string> mMesssage;
};

class XmlMessageAssembler : public MessageAssembler
{
  public:
    virtual void createHeader()
    {
      mMesssage.push_back(std::string("<header>foobar_header</header>"));
    }
    virtual void createBody()
    {
      mMesssage.push_back(std::string("<body>foo</body>"));
      mMesssage.push_back(std::string("<body>bar</body>"));
      mMesssage.push_back(std::string("<body>foobar</body>"));
    }
    virtual void createFooter()
    { 
      mMesssage.push_back(std::string("<footer>foobar_footer</footer>"));
    }
};

class TxtMessageAssembler : public MessageAssembler
{
  public:
    virtual void createHeader()
    {
      mMesssage.push_back(std::string("foobar_header"));
    }
    virtual void createBody()
    {
      mMesssage.push_back(std::string("foo"));
      mMesssage.push_back(std::string("bar"));
      mMesssage.push_back(std::string("foobar"));
    }
    virtual void createFooter()
    { 
      mMesssage.push_back(std::string("foobar_footer"));
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

