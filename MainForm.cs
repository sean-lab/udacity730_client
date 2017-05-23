using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Thrift;
using Thrift.Collections;
using System.Runtime.Serialization;
using Thrift.Protocol;
using Thrift.Transport;
using Thrift.Server;
using System.IO;

namespace SVHNClient
{
    public partial class MainForm : Form
    {
        TTransport transport; // Thrift default transport class
        TProtocol protocol; // Thrift default protocol class
        SVHN.Client client; // Thrift SVHN service interface

        WebCam webcam; // IP Cam API interface

        private Pen _Pen = new Pen(Color.Black);
        private Point? _Previous = null;
        private string keystr = "";

        public MainForm()
        {
            InitializeComponent();

            webcam = new WebCam();
            webcam.InitializeWebCam(ref canvas);
        }


        private void btnRecognize_Click(object sender, EventArgs e)
        {
            SVHNQuery query = new SVHNQuery();

            query.Filename = "temp.jpg";
            MemoryStream stream = new MemoryStream();

            // Webcam captures image in 640*480 size. 
            // So, before send image to backend, trim Image to 128 * 64. 
            using (Bitmap bmp = new Bitmap(canvas.Image))
            {
                var newImg = bmp.Clone(
                    new Rectangle { X = 0, Y = 0, Width = canvas.Width, Height = canvas.Height},
                    bmp.PixelFormat);
                canvas.Image = newImg;
            }

            // Convert the image into a byte stream
            canvas.Image.Save(stream, System.Drawing.Imaging.ImageFormat.Jpeg);
            query.Image = stream.GetBuffer();

            try
            {
                // Send the image and receive recognition result.
                string result = client.recognize(query);
                lblResult.Text = result;
            }
            catch (InvalidOperation io)
            {
                Console.WriteLine("Invalid operation: " + io.Why);
            }
        }

        private void MainForm_Load(object sender, EventArgs e)
        {
            
        }

        private void canvas_MouseDown(object sender, MouseEventArgs e)
        {
            _Previous = e.Location;
            canvas_MouseMove(sender, e);
        }

        private void canvas_MouseUp(object sender, MouseEventArgs e)
        {
            _Previous = null;
        }

        private void canvas_MouseMove(object sender, MouseEventArgs e)
        {
            if (!rdoDraw.Checked)
                return;
            
            if (_Previous != null)
            {
                if (canvas.Image == null)
                {
                    Bitmap bmp = new Bitmap(canvas.Width, canvas.Height);
                    using (Graphics g = Graphics.FromImage(bmp))
                    {
                        g.Clear(Color.White);
                    }
                    canvas.Image = bmp;
                }
                using (Graphics g = Graphics.FromImage(canvas.Image))
                {
                    _Pen.Width = 3.0f;
                    g.DrawLine(_Pen, _Previous.Value, e.Location);
                }
                canvas.Invalidate();
                _Previous = e.Location;
            }
        }

        private void btnConnect_Click(object sender, EventArgs e)
        {
            try
            {
                transport = new TSocket(txtServerIP.Text.Trim(), 5425);
                protocol = new TBinaryProtocol(transport);
                client = new SVHN.Client(protocol);


                /*
                 * 
                 *     tfactory = TTransport.TBufferedTransportFactory()
    pfactory = TBinaryProtocol.TBinaryProtocolFactory()
                 */
                transport.Open();

                btnRecognize.Enabled = true;
            }
            catch (TApplicationException x)
            {
                Console.WriteLine(x.StackTrace);
            }
        }

        private void canvas_MouseClick(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Right)
            {
                canvas.Image = null;
                keystr = "";
            }
        }

        private void MainForm_KeyDown(object sender, KeyEventArgs e)
        {
            if (!rdoDraw.Checked)
                return;

            switch (e.KeyCode)
            {
                case Keys.D0:
                    keystr += "0";
                    break;
                case Keys.D1:
                    keystr += "1";
                    break;
                case Keys.D2:
                    keystr += "2";
                    break;
                case Keys.D3:
                    keystr += "3";
                    break;
                case Keys.D4:
                    keystr += "4";
                    break;
                case Keys.D5:
                    keystr += "5";
                    break;
                case Keys.D6:
                    keystr += "6";
                    break;
                case Keys.D7:
                    keystr += "7";
                    break;
                case Keys.D8:
                    keystr += "8";
                    break;
                case Keys.D9:
                    keystr += "9";
                    break;
            }

            if (canvas.Image == null)
            {
                Bitmap bmp = new Bitmap(canvas.Width, canvas.Height);
                using (Graphics g = Graphics.FromImage(bmp))
                {
                    g.Clear(Color.White);
                }
                canvas.Image = bmp;
            }
            using (Graphics g = Graphics.FromImage(canvas.Image))
            {
                _Pen.Width = 3.0f;
                g.DrawString(keystr, new Font("Lucida Console", 25.0f, FontStyle.Bold), Brushes.Black, new PointF(10.0f, 10.0f));
            }
            canvas.Invalidate();
        }

        private void canvas_Paint(object sender, PaintEventArgs e)
        {

        }

        private void rdoDraw_CheckedChanged(object sender, EventArgs e)
        {
            if (rdoDraw.Checked)
            {
                webcam.Stop();
                lblExplainClear.Visible = true;
            }
        }

        private void rdoCam_CheckedChanged(object sender, EventArgs e)
        {
            if (rdoCam.Checked)
            {
                webcam.Start();
                lblExplainClear.Visible = false;
            }
        }
    }
}
