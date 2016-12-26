<? 

switch($page)
{
    case "home":
        switch($sub)
        {
            case "news":
                $subButton1 = "<img src=\"images/b2_coin_rond.png\" border=\"0\" alt=\"\">";
                $subButton2 = "&nbsp;";
                $subButton3 = "<a href=\"index.php?page=home&sub=news\"><img src=\"images/b2_news_1.png\" border=\"0\" alt=\"\"></a>";
                $subButton4 = "<a href=\"index.php?page=home&sub=status\"><img src=\"images/b2_status_2.png\" border=\"0\" alt=\"\"></a>";
                $currentPage = "news.php";
                break;
            case "status":
                $subButton1 = "<img src=\"images/b2_coin_rond.png\" border=\"0\" alt=\"\">";
                $subButton2 = "&nbsp;";
                $subButton3 = "<a href=\"index.php?page=home&sub=news\"><img src=\"images/b2_news_2.png\" border=\"0\" alt=\"\"></a>";
                $subButton4 = "<a href=\"index.php?page=home&sub=status\"><img src=\"images/b2_status_1.png\" border=\"0\" alt=\"\"></a>";
                $currentPage = "status.php";
                break;
            default:
                $sub="news";
                $subButton1 = "<img src=\"images/b2_coin_rond.png\" border=\"0\" alt=\"\">";
                $subButton2 = "&nbsp;";
                $subButton3 = "<a href=\"index.php?page=home&sub=news\"><img src=\"images/b2_news_1.png\" border=\"0\" alt=\"\"></a>";
                $subButton4 = "<a href=\"index.php?page=home&sub=status\"><img src=\"images/b2_status_2.png\" border=\"0\" alt=\"\"></a>";
                $currentPage = "news.php";
        }
        break;

    case "shots":
        switch($sub)
        {
            case "win":
                $subButton1 = "<img src=\"images/b2_coin_rond.png\" border=\"0\" alt=\"\">";
                $subButton2 = "&nbsp;";
                $subButton3 = "<a href=\"index.php?page=shots&sub=win\"><img src=\"images/b2_win_1.png\" border=\"0\" alt=\"\"></a>";
                $subButton4 = "<a href=\"index.php?page=shots&sub=linux\"><img src=\"images/b2_linux_2.png\" border=\"0\" alt=\"\"></a>";
                $currentPage = "win.php";
                break;
            case "linux":
                $subButton1 = "<img src=\"images/b2_coin_rond.png\" border=\"0\" alt=\"\">";
                $subButton2 = "&nbsp;";
                $subButton3 = "<a href=\"index.php?page=shots&sub=win\"><img src=\"images/b2_win_2.png\" border=\"0\" alt=\"\"></a>";
                $subButton4 = "<a href=\"index.php?page=shots&sub=linux\"><img src=\"images/b2_linux_1.png\" border=\"0\" alt=\"\"></a>";
                $currentPage = "linux.php";
                break;
            default:
                $sub="win";
                $subButton1 = "<img src=\"images/b2_coin_rond.png\" border=\"0\" alt=\"\">";
                $subButton2 = "&nbsp;";
                $subButton3 = "<a href=\"index.php?page=shots&sub=win\"><img src=\"images/b2_win_1.png\" border=\"0\" alt=\"\"></a>";
                $subButton4 = "<a href=\"index.php?page=shots&sub=linux\"><img src=\"images/b2_linux_2.png\" border=\"0\" alt=\"\"></a>";
                $currentPage = "win.php";
        }
        break;

    case "down":
        switch($sub)
        {
            case "files":
                $subButton1 = "<img src=\"images/b2_coin_rond.png\" border=\"0\" alt=\"\">";
                $subButton2 = "<a href=\"index.php?page=down&sub=files\"><img src=\"images/b2_files_1.png\" border=\"0\" alt=\"\"></a>";
                $subButton3 = "<a href=\"index.php?page=down&sub=faq\"><img src=\"images/b2_faq_2.png\" border=\"0\" alt=\"\"></a>";
                $subButton4 = "<a href=\"index.php?page=down&sub=doc\"><img src=\"images/b2_doc_2.png\" border=\"0\" alt=\"\"></a>";
                $currentPage = "files.php";
                break;
            case "faq":
                $subButton1 = "<img src=\"images/b2_coin_rond.png\" border=\"0\" alt=\"\">";
                $subButton2 = "<a href=\"index.php?page=down&sub=files\"><img src=\"images/b2_files_2.png\" border=\"0\" alt=\"\"></a>";
                $subButton3 = "<a href=\"index.php?page=down&sub=faq\"><img src=\"images/b2_faq_1.png\" border=\"0\" alt=\"\"></a>";
                $subButton4 = "<a href=\"index.php?page=down&sub=doc\"><img src=\"images/b2_doc_2.png\" border=\"0\" alt=\"\"></a>";
                $currentPage = "faq.php";
                break;
            case "doc":
                $subButton1 = "<img src=\"images/b2_coin_rond.png\" border=\"0\" alt=\"\">";
                $subButton2 = "<a href=\"index.php?page=down&sub=files\"><img src=\"images/b2_files_2.png\" border=\"0\" alt=\"\"></a>";
                $subButton3 = "<a href=\"index.php?page=down&sub=faq\"><img src=\"images/b2_faq_2.png\" border=\"0\" alt=\"\"></a>";
                $subButton4 = "<a href=\"index.php?page=down&sub=doc\"><img src=\"images/b2_doc_1.png\" border=\"0\" alt=\"\"></a>";
                $currentPage = "doc.php";
                break;
            default:
                $sub="files";
                $subButton1 = "<img src=\"images/b2_coin_rond.png\" border=\"0\" alt=\"\">";
                $subButton2 = "<a href=\"index.php?page=down&sub=files\"><img src=\"images/b2_files_1.png\" border=\"0\" alt=\"\"></a>";
                $subButton3 = "<a href=\"index.php?page=down&sub=faq\"><img src=\"images/b2_faq_2.png\" border=\"0\" alt=\"\"></a>";
                $subButton4 = "<a href=\"index.php?page=down&sub=doc\"><img src=\"images/b2_doc_2.png\" border=\"0\" alt=\"\"></a>";
                $currentPage = "files.php";
        }
        break;
        
    case "misc":
        switch($sub)
        {
            case "about":
                $subButton1 = "<img src=\"images/b2_coin_rond.png\" border=\"0\" alt=\"\">";
                $subButton2 = "&nbsp;";
                $subButton3 = "<a href=\"index.php?page=misc&sub=about\"><img src=\"images/b2_about_1.png\" border=\"0\" alt=\"\"></a>";
                $subButton4 = "<a href=\"index.php?page=misc&sub=links\"><img src=\"images/b2_links_2.png\" border=\"0\" alt=\"\"></a>";
                $currentPage = "about.php";
                break;
            case "links":
                $subButton1 = "<img src=\"images/b2_coin_rond.png\" border=\"0\" alt=\"\">";
                $subButton2 = "&nbsp;";
                $subButton3 = "<a href=\"index.php?page=misc&sub=about\"><img src=\"images/b2_about_2.png\" border=\"0\" alt=\"\"></a>";
                $subButton4 = "<a href=\"index.php?page=misc&sub=links\"><img src=\"images/b2_links_1.png\" border=\"0\" alt=\"\"></a>";
                $currentPage = "links.php";
                break;
            default:
                $sub="about";
                $subButton1 = "<img src=\"images/b2_coin_rond.png\" border=\"0\" alt=\"\">";
                $subButton2 = "&nbsp;";
                $subButton3 = "<a href=\"index.php?page=misc&sub=about\"><img src=\"images/b2_about_1.png\" border=\"0\" alt=\"\"></a>";
                $subButton4 = "<a href=\"index.php?page=misc&sub=links\"><img src=\"images/b2_links_2.png\" border=\"0\" alt=\"\"></a>";
                $currentPage = "about.php";
        }
        break;
        
    default:
        $page="home";
        $sub="news";
        $subButton1 = "<img src=\"images/b2_coin_rond.png\" border=\"0\" alt=\"\">";
        $subButton2 = "&nbsp;";
        $subButton3 = "<a href=\"index.php?page=home&sub=news\"><img src=\"images/b2_news_1.png\" border=\"0\" alt=\"\"></a>";
        $subButton4 = "<a href=\"index.php?page=home&sub=status\"><img src=\"images/b2_status_2.png\" border=\"0\" alt=\"\"></a>";
        $currentPage = "news.php";
}


include("haut.php");
include($currentPage);
include("bas.php");
?>


                        